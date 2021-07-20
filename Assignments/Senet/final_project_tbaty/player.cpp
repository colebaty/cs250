#include <random>
#include "player.h"

using namespace std;

Player::Player()
{
    _playerNumber = EMPTY;
    _score = 0;
    for (int i = 0; i < 5; i++)
        _playerPieces[i] = EMPTY;
}

Player::Player(char playerNumber)
{
    _score = 0;

    if (playerNumber == P1)
    {
        _playerNumber = P1;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                _playerPieces[i] = ONE;
                break;
            case 1:
                _playerPieces[i] = TWO;
                break;
            case 2:
                _playerPieces[i] = THREE;
                break;
            case 3:
                _playerPieces[i] = FOUR;
                break;
            case 4:
                _playerPieces[i] = FIVE;
                break;
            
            default:
                break;
            }
        }
    }
    else
    {
        _playerNumber = P2;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                _playerPieces[i] = A;
                break;
            case 1:
                _playerPieces[i] = B;
                break;
            case 2:
                _playerPieces[i] = C;
                break;
            case 3:
                _playerPieces[i] = D;
                break;
            case 4:
                _playerPieces[i] = E;
                break;
            
            default:
                break;
            }
        }
    }
}

void Player::setPlayer(char playerNumber)
{
    if (playerNumber == P1)
    {
        _playerNumber = P1;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                _playerPieces[i] = ONE;
                break;
            case 1:
                _playerPieces[i] = TWO;
                break;
            case 2:
                _playerPieces[i] = THREE;
                break;
            case 3:
                _playerPieces[i] = FOUR;
                break;
            case 4:
                _playerPieces[i] = FIVE;
                break;
            
            default:
                break;
            }
        }
    }
    else
    {
        _playerNumber = P2;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                _playerPieces[i] = A;
                break;
            case 1:
                _playerPieces[i] = B;
                break;
            case 2:
                _playerPieces[i] = C;
                break;
            case 3:
                _playerPieces[i] = D;
                break;
            case 4:
                _playerPieces[i] = E;
                break;
            
            default:
                break;
            }
        }
    }

}

void Player::rollDie(int& die)
{
    die = rand() % 5 + 1;
}

int Player::choosePiece(Board *b, char piece)
{
    //if piece doesn't belong to player, invalid selection
    if(b->belongsTo(piece) != this->getPlayerNumber())
        return INVALID;

    //is the piece available
    //player's deck should only contain pieces belonging to player
    //piece selection is validated implicitly
    if (!isInPlay(piece))
        return INVALID;
    
    return b->find(piece);

}

bool Player::isInPlay(char piece)
{
    for (int i = 0; i < 5; i++)
    {
        if (_playerPieces[i] == piece)
            return true;
    }

    return false;
}

void Player::movePiece(Board *b, int origin, int target, char mode) 
{
    /*
        all moves are essentially swapping:
            - ADVANCE is swapping an empty square for an occupied square
            - CAPTURE is swapping the contents of two occcupied squares

        The Referee will validate each move before it is permitted, so
        there is no need for proofing here. Validation includes trap square
        behavior.
    */
    
    switch (target)
    {

    case FINISH:
        clearPiece(b, origin);
        break;
    
    default:
        b->swap(origin, target);
    }
}

void Player::displayPieces(ostream& out)
{
    for (int i = 0; i < 5; i++)
        out << "|" << _playerPieces[i];
    
    out << "|";

}

void Player::clearPiece(Board *b, int square)
{
    //remove piece from player's deck
    char piece = b->getSquare(square);
    for (int i = 0; i < 5; i++)
    {
        if (_playerPieces[i] == piece)
            _playerPieces[i] = EMPTY;
    }

    //remove piece from board
    b->setSquare(square, EMPTY);
    _score++;
}

// bool Player::isProtected(Board *b, int square)
// {
//     char forward = EMPTY;
//     char rear = EMPTY;
//     //forward neighbor
//     if (square > 0 && square < 30)
//     {
//         forward = b->getSquare(square + 1);
//         rear = b->getSquare(square -1);
//     }
    
//      if ((b->belongsTo(forward) || b->belongsTo(rear))
//          && this->isPlayerOne() == _playerOne)
//          return true;
    
//     return false;

//     //rear neighbor
// }