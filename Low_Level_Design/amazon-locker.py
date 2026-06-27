"""
    Design a locker system like Amazon Locker where delivery drivers can deposit packages and customers can pick them up using a code.

    1. Primary Capabilities
    2. Error Handling 
    3. Scope Boundaries

    Requirements :
    1. Carrier deposits a package by specifying size (small, medium, large)
        A. System assigns an available compartment of matching size 
        B. Opens compartment and returns access tokens, or error if no space 
    
    2. Upon successful deposit, an access token is generated and returned
        A. One Access token per package
    
    3. User retrieves package by entering access token
        A. System validates code and opens compartment 
        B. Throws specific error if the code is expired or invalid
    
    4. Access tokens expire after 7 days
        A. Expired codes are rejected if used for pickup
        B. Package remains in compartment until staff removes it 
    
    5. Staff can open all expired compartments to manually handle packages 
        A. System opens all compartments with expired tokens
        B. Staff physically removes packages and returns them to sender

    
    Out of Scope :
    1. How the package gets to the locker (delivery logistics)
    2. How the access token reaches the customer (SMS/email notification)

    
    Entities : 
    1. Compartments
    2. Locker
    3. AccessToken


    Class Design :

"""

class Locker:
    - compartments: Compartments[]
    - accessTokensMapping: Map<string, AccessTokens>

    + depositPackage(size) -> string | error 
    + pickup(string) -> void | error 
    + openExpiredCompartment() -> void 


class AccessToken:
    - code: string 
    - expiration: timestamp 
    - compartment: Compartment 

    + isExpired() -> boolean 
    + getCompartment() -> Compartment 
    + getCode() -> string 


class Compartment:
    - size: Size  # enum {SMALL MEDIUM LARGE}
    - occupied: boolean 

    + isOccupied() -> boolean 
    + markOccupied() -> void 
    + markFree() -> void 
    + open() -> void
    + getSize() -> Size 


# Implementation 
# 1. Core Logic 
# 2. Edge Cases 

class Locker:
    depositPackage(Size):
        """
            Core Logic :
            1. Find Available compartment of right size 
            2. Open the compartment 
            3. Mark occupied the compartment 
            4. Generating an access token 
            5. Store the access token
            6. Return the access token code

            # Edge Cases:
            1. No compartment available of requested size -> throw error 
        
        """

        compartment = getAvailableCompartment(size)
        if compartment == null 
            throw error("No available compartment of that size")
        compartment.open() 
        compartment.markOccupied()
        accessToken = generateAccessToken(compartment)
    
        code = accesstoken.getCode
        accessTokenMapping[code] = accessToken
        
        return code 


    private getAvailableCompartment(size)
        """
            1. Scan all compartments 
            2. For each, see if right size and free
            3. First that matches, return it

        """
    
        for c in compartments:
            if c.getSize() == size && !c.isOccupied():
                return c 
            
        return null


    pickup(code : string) 
        """
            Core Logic: 
            1. Look up the code to get accessToken
            2. get the compartment
            3. Open the compartment 
            4. Mark the compartment as free
            5. remove accessCode from the map

            Edge Cases:
            1. Validation of the code itself, if empty -> throw
            2. Code is not in mapping -> throw 
            3. accessToken is expired -> throw

        """
    
        if code.isEmpty():
            throw error("Empty Code")

        accessToken = accessTokenMapping[code] 
        if accessToken == null:
            throw error("Invalid Code")

        if accessToken.isExpired():
            throw error("Expired Code")

        compartment = accessToken.getCompartment() 
        compartment.open()
        compartmet.markFree() 
        accessTokensMapping.remove(code)


    openExpiredCompartments():
        """
            Core Logic:
            1. Scan through all access tokens in mapping 
            2. Find the expired ones
            3. Get the compartment of each 
            4. Open those compartments
            5. Mark the compartment available again
            6. Remove access from map?? Not instant (3+ Months)

            Edge Cases:
            Implicitly handled
        
        """
    
        for code, accessToken in accessTokenMapping:
            if accessToken.isExpired():
                compartment = accessToken.getCompartment()
                compartment.open()
                compartment.markFree()

        # An extra loop to clear out 3+ months old access tokens
    
