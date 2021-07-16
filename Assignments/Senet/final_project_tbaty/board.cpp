#ifdef DEBUG
    #define EMPTIES
#endif
#include <iostream>
#include "senet_constants.h"
#include "board.h"

using namespace std;

Board::Board()
{
    initialize();
}

char Board::setSquare(const int& square, char piece, bool capture)
{
    if (!capture)
    {
        _board[square] = piece;
        return _board[square];
    }

    return INVALID;
}

void Board::initialize()
{
    for (int i = 0; i < 30; i++)
    {
        switch (i)
        {
        case 0:
            setSquare(i, A);
            break;
        case 1:
            setSquare(i, ONE);
            break;
        case 2:
            setSquare(i, B);
            break;
        case 3:
            setSquare(i, TWO);
            break;
        case 4:
            setSquare(i, C);
            break;
        case 5:
            setSquare(i, THREE);
            break;
        case 6:
            setSquare(i, D);
            break;
        case 7:
            setSquare(i, FOUR);
            break;
        case 8:
            setSquare(i, E);
            break;
        case 9:
            setSquare(i, FIVE);
            break;
        case TRAP:
            setSquare(i, TRAP_PIECE);
            break;
        
        default:
            setSquare(i, EMPTY);
            break;
        }
    }
}

bool Board::belongsTo(char piece)
{
    switch (piece)
    {
    case ONE:
    case TWO:
    case THREE:
    case FOUR:
    case FIVE:
        return true;
    default:
        return false;
    }
}

void Board::swap(int a, int b)
{
    char pieceA = getSquare(a);
    char pieceB = getSquare(b);

    setSquare(a, EMPTY);
    setSquare(b, EMPTY);

    setSquare(a, pieceB);
    setSquare(b, pieceA);
}

void Board::display(ostream& out)
{
    /*
        TODO
            [ ] Fill in top and bottom rows. Wait until gameplay implementation 
                is finished because you'll need to account for cell expansion
                that will not be present in normal gameplay.
    */
    //cells | A| 1|
    for (int i = 0; i < 10; i++)
    {
        #ifdef EMPTIES
            char piece =getSquare(i);
            if (piece == EMPTY)
                out << "|  " <<  i;
            else
                out << "|  "<< piece;
        #else
            out << "| " << getSquare(i);
        #endif
    }

    out << "| " << endl;

    for (int i = 19; i > 9; i--)
    {
        #ifdef EMPTIES
            char piece =getSquare(i);
            if (piece == EMPTY)
                out << "| " <<  i;
            else
                out << "| "<< piece;
        #else
            out << "| " << getSquare(i);
        #endif
    }

    out << "| " << endl;

    for (int i = 20; i < 30; i++)
    {
        #ifdef EMPTIES
            char piece =getSquare(i);
            if (piece == EMPTY)
                out << "| " <<  i;
            else if (piece == TRAP_PIECE)
                out << "|  " << getSquare(i);
            else
                out << "| "<< piece;
        #else
            out << "| " << getSquare(i);
        #endif
    }

    out << "| " << endl;

}