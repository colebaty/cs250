# Semester Project - Senet

## Implement a Game of Senet

There are two players; each player has five pieces. The game is won by the first 
player to clear all their pieces from the board.

Players take turns rolling a five-sided die; pieces are moved according to the 
scheme outlined in [Piece Movement](#PieceMovement).

## Approach

Trying to represent actual gameplay through the ADT model.

- Players will move their own pieces
- Referee will validate Players' moves and govern special trap square behavior
- Referee and Players will need access to Board

Guard spaces as in Assg8.  Alternate turns as in Battleship Assignment.

## Concepts

### Trap Square

If a piece lands on the trap at Square 27, it is transported to Square 15. If 
Square 15 is occupied, the piece moves to the next unoccupied square.  This
suggests to me a repeat of the recursive function used in Assg8 to find a target 
square for a Player piece.

### Protection

A piece is _protected_ when an adjacent square contains a friendly piece. Protected
pieces cannot be captured.

### Capturing

If a target square contains an enemy piece, and the piece is unprotected, the 
enemy piece is _captured_, and the friendly piece and enemy piece swap places.


## ADTs

### Board

Board could just be a single `char` array of size 30. Since the Referee has access 
to the `enum`s in each of the Player ADTs, the Referee should determine whether 
piece placement is valid. Gameplay is linear, with the unique exception of the 
behavior of the trap square.

Board class should hold `const char INVALID = '0'` if possible.

Board Layout

|Board||||||||||
|-|-|-|-|-|-|-|-|-|-|
|1|2|3|4|5|6|7|8|9|10|
|20|19|18|17|16|LANDING|14|13|12|11|
|21|22|23|24|25|26|TRAP|28|29|30|

```cpp
enum Trap : int {TRAP = 27, LANDING = 15};
```
Trap Square @ 27
Trap Square Landing Target @ #15

Protection
```cpp
bool isProtected(int sqaure)
{
    //which player's piece is here?
    bool playerOne = false;
    switch (_board[square])
    {
    //PlayerOne pieces from enum
    case ONE:
    case TWO:
    case THREE:
    case FOUR:
    case FIVE:
        playerOne = true;
        break;
    default:
        break;
    }

    if (playerOne)
    {
        //check ahead
        switch (_board[square + 1])
        {
        //PlayerOne pieces from enum
        case ONE:
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
            return true;
        default:
            break;
        }

        //check behind
        switch (_board[square + 1])
        {
        case ONE:
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
            return true;
        default:
            break;

        }
    }
    else//playerTwo
    {
        //check ahead
        switch (_board[square + 1])
        {
        //PlayerOne pieces from enum
        case A:
        case B:
        case C:
        case D:
        case E:
            return true;
        default:
            break;
        }

        //check behind
        switch (_board[square - 1])
        {
        case A:
        case B:
        case C:
        case D:
        case E:
            return true;
        default:
            break;

        }

    }
}
```

### Player {#PieceMovement}

What does Player need?

```cpp
#include <rand>
#include <ctime>

void Player::rollDie(int& die)
{
    die = rand() % 5 + 1;
}
```
`die` is declared in `main` and passed to each player during gameplay.

- [ ] Where to initialize srand? `main`?

### Referee

- Interacts with Board, Player instances through pointer

#### Move validation

Referee receives (board), player, player origin square, num rolled on die. Player
origin square has been validated by `choosePiece()` method in Player ADT.

```cpp
//referee receives (board), player, player origin square, num rolled on die
```

## Piece Movement {#pieceMovement}

Individual piece movement should be validated by referee. That is, given the board
the player, the origin square, and the number rolled on the die, the Referee 
determines if the target square is a valid move, i.e. either unoccupied or occupied
by the opponent (capture).

Referee determines whether to roll again.

```cpp

int target = origin + numRolled;
bool rollAgain = false;
int result = INVALID;

switch (numRolled)
{
case 1:
case 4:
    rollAgain = true;
    break;
case 5:
    //move six (yes, six)
    target++;
    rollAgain = true;
    break;
default:
    break;
}

switch(target)
{
    case LANDING:
}

//move numRolled
if target unoccupied || (target occupied && not friendly)
    //capture target square implied by p.movePiece()
    result = target;
else if target occupied && friendly
    result = INVALID;

return result;
```
