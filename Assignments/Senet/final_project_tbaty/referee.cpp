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

    if (target > FINISH) return FINISH;
    if (target == TRAP) 
    {
        target = LANDING + 1;
        findLanding(b, target);
        return target;
    }

    //if target not empty && target is friendly
    if (b->getSquare(target) != EMPTY && isFriendlySquare(b, p, target))
        return INVALID;

    return target;
}

bool Referee::isFriendlySquare(Board *b, Player *p, int square)
{
    bool playerOne = p->isPlayerOne();
    char piece = b->getSquare(square);

    if (b->belongsTo(piece) == playerOne)
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
    if (b->getSquare(square) == EMPTY)
        return;
    else 
        findLanding(b, ++square);
}