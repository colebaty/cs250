#include <random>
#include "player.h"

using namespace std;

Player::Player()
{
    _playerOne = true;
}

Player::Player(bool playerOne)
{
    if (!playerOne)
        _playerOne = false;
    else
        _playerOne = true;
}

void Player::rollDie(int& die)
{
    die = rand() % 5 + 1;
}

int Player::movePiece(Board *b, int square, int numRolled)
{

}