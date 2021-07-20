#include <random>
#include "player.h"

using namespace std;

Player::Player()
{
    _playerNumber = EMPTY;
    _score = 0;
}

Player::Player(char playerNumber)
{
    _score = 0;

    if (playerNumber == P1)
        _playerNumber = P1;
    else
        _playerNumber = P2;
}

void Player::rollDie(int& die)
{
    die = rand() % 5 + 1;
}

int Player::choosePiece(Board *b, int square)
{
    if (square < 0 || square > 29)
        return INVALID;

    if (b->getSquare(square) == EMPTY)
        return INVALID;

    char piece = b->getSquare(square);
    if (b->belongsTo(piece) != this->getPlayerNumber())
        return INVALID;

    char next = b->getSquare(square + 1);
    // #ifdef DEBUG
    //     cout << "\tpiece: " << piece << endl;
    //     cout << "\tnext: " << next << endl;
    // #endif
    if (piece != EMPTY 
        && (b->belongsTo(piece) == this->getPlayerNumber())
        && (next == EMPTY))
    {
        cout << "here!" << endl;
        return square;
    }
    
    return INVALID;
    
}

void Player::movePiece(Board *b, int origin, int target) 
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

void Player::clearPiece(Board *b, int square)
{
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