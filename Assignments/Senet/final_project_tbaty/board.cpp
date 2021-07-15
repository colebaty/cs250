#include "board.h"

using namespace std;

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