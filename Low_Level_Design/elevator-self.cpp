/*
    Design an Elevator control System for a building. The system should handle multiple elevators, floor requests and move elevators
    efficiently to service requests.  

    1. Primary Cabilities
    2. Error Handling
    3. Scope Boundaries 


    Requirements:
    1. System manages 3 elevators serving 10 floors (0-9)
    2. Users can request an elevator from any floor (hall call). System decides which elevator to dispatch.
    3. Once inside, users can select one or more destination floors
    4. Simulation runs in discrete time steps (e.g., a `step()` or `tick()` call advances time)
    5. Elevator stops come in two types:
        - Hall calls: Request from a floor with direction (UP or DOWN)
        - Destination: Request from inside elevator (no direction specified)
    6. System handles multiple concurrent pickup requests across floors
    7. Invalid requests should be rejected (return false)
        - Non-existent floor numbers
    8. Requests for the current floor are treated as a no-op / already served (doors out of scope)

    Out of scope:
    - Weight capacity and passenger limits
    - Door open/close mechanics
    - Emergency stop functionality
    - Dynamic floor/elevator configuration
    - UI/rendering layer


    Class Entities :
    1. Elevator (class)
    2. Floor (number property)
    3. Request (class, need direction and potentially floor)
    4. ElevatorController

    Class Design:
*/


class ElevatorController :
    - elevators : List<Elevators>
    
    + ElevatorController()
    + requestElevator(floor, direction) -> boolean 
    + step() -> void


class Elevator:
    - floor : int 
    - direction : Direction
    - requests : Set<Requests>

    + Elevator() 
    + addRequests(request) -> boolean
    + step() -> void 
    + getFloor() -> int 
    + getDirection() -> Direction


enum Direction :
    UP 
    DOWN 
    IDLE 


class Requests :
    - floor int 
    - type : RequestType

    + Request(floor, type)
    + getFlooe() -> int 
    + getType() -> RequestType


enum RequestType :
    PICKUP_UP 
    PICKUP_DOWN
    DESTINATION


/*
    Implementation
*/

class ElevatorController :
    step():
    for e in elevators :
        e.step()


    requestElevator(floor, type = PICKUP_UP | PICKUP_DOWN):
    /*
        Core Logic: 
        1. Find the best elevator to handle this request.
        2. Send that request to that elevator

        Edge Case :
        1. FLoor out of bound -> throw error
    */

    if(floor < 0 || floor > 9) 
        throw Error ("Not a valid choice")

    request = Request(floor, type)
    best = selectBestElevator(request)
    return best.addRequests(request)


    private selectBestElevator(request) :
    /*
        Core Logic : 
        1. Try to find the elevator moving towards
        2. If none, try idle elevators
        3. Find nearest
    */

    best = findMovingTowards(requests)
    if best != null:
        return best 
    
    best = findNearestIdle(request.getFloor())
    if best != null:
        return beest 

        return findNearest(request.getFloor())

    
    private findMovingTowards(request) :
    /*
        Core Logic:
        1. Scan elevators moving in that direction
        2. Keep track of closest
        3. Return closest.
    */

    floor = request.getFloor();
    direction = request.getType() == PICKUP_UP ? UP : DOWN

    nearest = null
    minDistance = MAX_VALUE

    for e in elevators :
        if e.getDirection != direction
            continue 
        
        if((direction == UP && e.getFloor() > floor) || (direction == DOWN && e.getFloor() < floor))
            continue
        
        distance = abs(e.getFloor() - floor)
        if distance < minDistance 
            minDistance = distance 
            nearest = e 

        return nearest


class Elevator:
    step():
    /*
        Core Logic :
        1. If idle with requests, pick direction towards nearest request
        2. Check if we should stop of the current floor (matches a hall call or a destination)
        3. If no requests ahead of us (and other requests pending), reverse
        4. Move on floor in current direction 

        Edge Cases:
        1. no requests -> Set IDLE state
        2. Stop move can't happen in same tick and reverse and move
    */

    // Case 1: Nothing to do
    if requests.isEmpty()
        direction = IDLE
        return

    // Case 2: If idle, pick a direction based on nearest request
    if direction == IDLE
        // Find the nearest request to establish initial direction
        nearest = null
        minDistance = Integer.MAX_VALUE

        for req in requests
            distance = abs(req.getFloor() - currentFloor)
            if distance < minDistance ||
                (distance == minDistance && (nearest == null || req.getFloor() < nearest.getFloor()))
                minDistance = distance
                nearest = req

        direction = (nearest.getFloor() > currentFloor) ? UP : DOWN

    // Case 3: Check if we should stop at current floor
    // Check pickup requests matching our direction, plus any destination requests
    pickupType = (direction == UP) ? PICKUP_UP : PICKUP_DOWN
    pickupRequest = Request(currentFloor, pickupType)
    destinationRequest = Request(currentFloor, DESTINATION)

    if requests.contains(pickupRequest) || requests.contains(destinationRequest)
        requests.remove(pickupRequest)
        requests.remove(destinationRequest)
        // Note: If Request(currentFloor, PICKUP_DOWN) exists but we're going UP,
        // it survives and will be serviced on the return trip going DOWN.
        // This is correct - we only pick up passengers going our direction.

        if requests.isEmpty()
            direction = IDLE
        return  // we stopped this tick, don't move

    // Case 4: Reverse if no requests ahead
    if !hasRequestsAhead(direction)
        direction = (direction == UP) ? DOWN : UP
        return  // don't move this tick, let next tick check for stops

    // Case 5: Move one floor
    if direction == UP
        currentFloor++
    else if direction == DOWN
        currentFloor--
         

