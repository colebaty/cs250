#include <iostream>

#include "player.h"

Player::Player()
{
    _board = new Board();
    _piecesOnBoard = 4;
    _numTurns = 0;
}

Player::Player(Board *board)
{
    initialize(board);
}

Player::~Player()
{
    delete [] _board;
}

void Player::initialize(Board *board, int numPieces, int numTurns)
{
    _piecesOnBoard = numPieces;
    _numTurns = numTurns;
    _board = board;
}

bool Player::isValidSelection(int row, int col)
{
    //check if on board
    if (row > 9 || row < 0 || col > 9 || col < 0)
        return false;

    char square = _board->getSquare(row, col);
    switch (square)
    {
    case PLAYER:
    case OBSTACLE:
        return true;
    case EMPTY:
    case GOAL:
        return false;
    }

    //if they get here, something is wrong and it's not a valid move
    return false;
}

bool Player::choosePiece(int& row, int& col)
{
    return isValidSelection(row, col);
}

char Player::movePiece(int& row, int& col, char dir)
{
    char piece = _board->getSquare(row, col);
    return _board->movePiece(piece, row, col, dir);
}

void Player::finishTurn(char result)
{
    _numTurns++;
    if (result == GOAL) clearPiece();
}