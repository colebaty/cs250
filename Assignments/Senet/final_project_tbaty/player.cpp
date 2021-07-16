#include <random>
#include "player.h"

using namespace std;

Player::Player()
{
    _playerOne = true;
    _numPieces = 5;
}

Player::Player(bool playerOne)
{
    _numPieces = 5;

    if (!playerOne)
        _playerOne = false;
    else
        _playerOne = true;
}

void Player::rollDie(int& die)
{
    die = rand() % 5 + 1;
}

int Player::movePiece(Board *b, int origin, int numRolled)
{
}
