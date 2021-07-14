#include "board.h"
#include <iostream>

using namespace std;

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

void Board::displayBoard(std::ostream& out)
{
    //print col headers
    out << "  0 1 2 3 4 5 6 7 8 9" << endl
        << " --------------------" << endl;

    for (int row = 0; row < 10; row++)
    {
        out << row << "|";
        for (int col = 0; col < 10; col++)
        {
            out << getSquare(row, col) << "|";
        }

        out << endl <<  " --------------------" << endl;
    }
}

bool Board::isNeighborFree(char piece, int row, int col, char dir)
{
    //check for free neighbor

    char neighbor;
    switch (dir)
    {
        case UP: 
        {
            //on board?
            if (row - 1 < 0) return false;
            neighbor = getSquare(row - 1, col);
            break;
        }
        case DOWN:
        {
            if (row + 1 > 9) return false;
            neighbor = getSquare(row + 1, col);
            break;
        }
        case LEFT:
        {
            if (col - 1 < 0) return false;
            neighbor = getSquare(row, col - 1);
            break;
        }
        case RIGHT:
        {
            if (col + 1 > 9) return false;
            neighbor = getSquare(row, col + 1);
            break;
        }
    }

    switch (piece)
    {
    case PLAYER:
        // if (neighbor != EMPTY && neighbor != GOAL) return false;
        if (neighbor == EMPTY || neighbor == GOAL) return true;
        else return false;
    case OBSTACLE:
        if (neighbor != EMPTY) return false;
    }

    return true;

}

void Board::findTarget(int& row, int& col, char dir)
{
    //base case: square occupied
    if (!isNeighborFree(PLAYER, row, col, dir))
    {
        return;
    }
    else
    {
        switch (dir)
        {
        case UP:
            row--;
            break;
        case DOWN:
            row++;
            break;
        case LEFT:
            col--;
            break;
        case RIGHT:
            col++;
            break;
        }
        findTarget(row, col, dir);
    }
}

char Board::movePiece(char piece, int row, int col, char dir)
{
    if (!isNeighborFree(piece, row, col, dir))
        return INVALID;
    
    switch (piece)
    {
    case PLAYER:
        //unset origin
        setSquare(EMPTY, row, col);
        //find target
        findTarget(row, col, dir);
        if (getSquare(row, col) == GOAL) return GOAL;
        else
        {
            //set target
            setSquare(piece, row, col);
            return getSquare(row, col);
        }
        break;
    
    case OBSTACLE:
        switch (dir)
        {
        case UP:
            //set target
            setSquare(piece, row - 1, col);
            //unset origin
            setSquare(EMPTY, row, col);
            return getSquare(row - 1, col);
        
        case DOWN:
            //set target
            setSquare(piece, row + 1, col);
            //unset origin
            setSquare(EMPTY, row, col);
            return getSquare(row + 1, col);
        
        case LEFT:
            //set target
            setSquare(piece, row, col -1 );
            //unset origin
            setSquare(EMPTY, row, col);
            return getSquare(row, col - 1);
        
        case RIGHT:
            //set target
            setSquare(piece, row, col + 1);
            //unset origin
            setSquare(EMPTY, row, col);
            return getSquare(row, col + 1);
        }
        break;
    }

    //if they got here, something went wrong
    return INVALID;
}