#include "board.h"

Board::Board()
{
    initialize();
}

void Board::initialize()
{
    //set all to EMPTY
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            setSquare(EMPTY, i, j);
        }
    }

    //player pieces
    setSquare(PLAYER, 9, 1);
    setSquare(PLAYER, 9, 3);
    setSquare(PLAYER, 9, 5);
    setSquare(PLAYER, 9, 7);

    //obstacles
    setSquare(OBSTACLE, 8, 1);
    setSquare(OBSTACLE, 8, 3);
    setSquare(OBSTACLE, 8, 5);
    setSquare(OBSTACLE, 8, 7);
    setSquare(OBSTACLE, 3, 3);
    setSquare(OBSTACLE, 3, 6);
    setSquare(OBSTACLE, 0, 3);
    setSquare(OBSTACLE, 0, 6);

    //goals
    setSquare(GOAL, 0, 4);
    setSquare(GOAL, 0, 5);
}

//stub to test Player
char Board::getSquare(int row, int col)
{
    return _board[row][col];
}

void Board::setSquare(char piece, int row, int col)
{
    _board[row][col] = piece;
}