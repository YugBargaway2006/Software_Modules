"""
    Build a two-player Connect Four game. Players take dropping discs into a 7-column, 6-row board. The first to align four of their own discs
    vertically, horizontally or diagonally wins.

    1. Primary Capabilities
    2. Error Handling
    3. Scope Boundaries

    Requirements :
    1. Two players take turns dropping discs into a 7-column, 6-row board
    2. A disc falls to the lowest available row in the chosen column
    3. The game ends when :
        A. A player gets four discs in a row (vertically, horizontally or diagonally). They win.
        B. The board is full, It's a draw
    4. Invalid moves should be rejected cleanly. 
        A. Dropping a disc in a full column
        B. Moving out of place
        C. Moing after the game is over
    
    Out of Scope : 
    1. UI Support
    2. Concurrent Games


    Entities : 
    1. Game
    2. Board
    3. Players
    4. Disc

    " Single Responsibility Principle (SRP) "

    
    Class Design : 

"""

class Game:
    # Structures 
    - player1 : Player 
    - player2 : Player 
    - currentPlayer : Player 
    - board : Board 
    - state : GameState // IN_PROGRESS , WON , DRAW 
    - winner? : Player

    # Behaviours 
    + Game(player1, player2)
    + makeMove(player, column) -> bool 
    
    - getCurrentPlayer() 
    - getGameState()
    - getWinner()
    # - getBoard() 


class Board:
    # Structures 
    - row : int  # 6
    - column : int  # 7
    - grid : DiscColor?[row][column]

    # Behaviours 
    + canPlace(column) -> bool 
    + placeDisc(column, color) -> int  # -1 for handling error conditions
    + isFull() -> bool 
    + checkWin(row, color, color) -> bool 

    - getRow()
    - getCol()


enum DiscColor :
    RED 
    BLUE 


class Player:
    # Structures 
    - color : DiscColor
    - name : string 

    + getName() -> string 
    + getColor() -> DiscColor



# Implementation 

class Game:
    makeMove(player, column) -> {success, message}
    """
        Core Logic :
        1. Place Disc
        2. Check Win
        3. Check Draw 
        4. Switch Turns

        Edges Cases :
        1. Game is already over 
        2. Wrong Player
    
    """

    if state == IS_PROGRESS 
        return false 
    if player != currentPlayer
        return false 

    row = board.placeDisc(column, player.getColor())
    if row == -1 
        return false

    if board.checkWin(row, column, player.getColor())
        state = WON 
        winner = player 
    else if board.isFull()
        state = DRAW 
    else 
        currentPlayer = {player == player1} ? player2 : player1 
    

class Board: 
    placeDisc(column, color) -> int :
    """
        Core Logic : 
        1. Find the lowest empty row for that column 
        2. Place Disc
        3. Return the row it landed to 

        Edge Cases :
        1. Column index is out of bound 
        2. Column is full
    
    """

        if column < 0 || column >= board.getCols() 
            return -1 
        if !board.canPlace(column)
            return -1 
        
        for row in rows -1 down to 0 
            if grid[row][column] == null 
                grid[row][column] = color 
                return row 
        
        return -1


    checkWin(row, column, color) ->

