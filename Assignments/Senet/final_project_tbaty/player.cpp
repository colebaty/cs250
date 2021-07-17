#include <random>
#include "player.h"

using namespace std;

Player::Player()
{
    _playerOne = true;
    _score = 5;
}

Player::Player(bool playerOne)
{
    _score = 5;

    if (!playerOne)
        _playerOne = false;
    else
        _playerOne = true;
}

void Player::rollDie(int& die)
{
    die = rand() % 5 + 1;
}

int Player::choosePiece(Board *b, Referee *r, int square)
{
    if (b->getSquare(square) == EMPTY)
        return INVALID;

    char piece = b->getSquare(square);
    if (piece != EMPTY && (b->belongsTo(piece) == _playerOne))
        return square;
    
    if (b->belongsTo(piece) != (this->isPlayerOne() == _playerOne))
        return INVALID;
    
}

void Player::movePiece(Board *b, int origin, int target) 
{
    /*
        all moves are essentially swapping:
            - ADVANCE is swapping an empty square for an occupied square
            - CAPTURE is swapping the contents of two occcupied squares

        The Referee will validate each move before it is permitted, so
        there is no need for proofing here.
    */
    b->swap(origin, target);
}

void Player::clearPiece(Board *b, int square)
{
    //remove piece from board
    b->setSquare(square, EMPTY);
    _score++;
}

bool Player::isProtected(Board *b, int square)
{
    char forward = EMPTY;
    char rear = EMPTY;
    //forward neighbor
    if (square > 0 && square < 30)
    {
        forward = b->getSquare(square + 1);
        rear = b->getSquare(square -1);
    }
    
     if ((b->belongsTo(forward) || b->belongsTo(rear))
         && this->isPlayerOne() == _playerOne)
         return true;
    
    return false;

    //rear neighbor
}