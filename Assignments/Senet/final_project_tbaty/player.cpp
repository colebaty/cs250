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
    if (!r->isFriendlySquare(b, this, square))
        return INVALID;
    
}

int Player::movePiece(Board *b, int origin, int numRolled)
{
}

void Player::clearPiece(Board *b, int square)
{
    //remove piece from board
    b->setSquare(square, EMPTY);
    _score++;
}