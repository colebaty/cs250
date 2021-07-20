#include "referee.h"

using namespace std;

Referee::Referee()
{
    _winner = EMPTY;
}

void Referee::announceWinnner(char winner, ostream& out)
{
    out << "Player ";
    switch (winner)
    {
    case P1:
        out << "One";
        break;
    
    case P2:
        out << "Two";
        break;
    }
    out << " wins!" << endl;
}

void Referee::setWinner(char& winner)
{
_winner = winner;
}

bool Referee::isWinner()
{
    return _winner != EMPTY;
}

char Referee::checkForWinner(Board* b, Player* p1, Player* p2)
{
if (!p1->hasPieces())
    _winner = P1;
else if (!p2->hasPieces())
    _winner = P2;

return _winner;
}

int Referee::validateMove(Board *b, Player *p, int origin, int numRolled)
{
    int target = origin + numRolled;

    if (numRolled == 5) ++target;//a roll of 5 means move 6 squares

    if (target > FINISH) return INVALID;//must land exactly on FINISH to clear
    if (target == TRAP) 
    {
        target = LANDING;
        findLanding(b, target);
        return target;
    }

    //if target is friendly, then it's not empty and we can't land there
    if (isFriendlySquare(b, p, target))
        return INVALID;
    else if (!isProtected(b, p, target))
        return target;

    return target;
}

bool Referee::isProtected(Board *b, Player *p, const int& target)
{
    //get which player
    char player = p->getPlayerNumber();

    //get neighboring squares
    char forward = EMPTY;
    char rear = EMPTY;
    if (target > 0 && target < 30)
    {
        forward = b->getSquare(target + 1);
        rear = b->getSquare(target -1);
    }
    
    if (b->belongsTo(forward) == p->getPlayerNumber() 
        || b->belongsTo(rear) == p->getPlayerNumber())
         return true;
    
    return false;
}

bool Referee::isFriendlySquare(Board *b, Player *p, int square)
{
    char playerOne = p->getPlayerNumber();
    char piece = b->getSquare(square);

    if (b->belongsTo(piece) == p->getPlayerNumber())
        return true;

    return false;
}

bool Referee::rollAgain(const int& die)
{
    switch (die)
    {
    case 1:
    case 4:
    case 5: 
        return true;
        break;
    
    default:
        return false;
    }

    return false;
}

void Referee::findLanding(Board *b, int& square)
{
    //base case - square is unoccupied
    if (b->getSquare(square) == EMPTY || b->getSquare(square) == LANDING_PIECE)
        return;
    else 
        findLanding(b, ++square);
}