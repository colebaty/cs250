#include <vector>

#include "referee.h"

using namespace std;

Referee::Referee()
{
    _winner = EMPTY;
}

void Referee::announceWinnner(ostream& out)
{
    out << "Player ";
    switch (_winner)
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

void Referee::setWinner(char winner)
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
    else if (!isProtected(b, target))
        return target;

    return INVALID;
}

bool Referee::isProtected(Board *b, const int& target)
{
    //get piece
    char piece = b->getSquare(target);
    if (piece == EMPTY)
        return false;

    //get which player
    char player = b->belongsTo(piece);

    //get neighboring squares
    char forward = EMPTY;
    char rear = EMPTY;
    if (target > 0 && target < 30)
    {
        forward = b->getSquare(target + 1);
        rear = b->getSquare(target - 1);
    }
    
    char fowner = b->belongsTo(forward);
    char rowner = b->belongsTo(rear);
    if (fowner == player || rowner == player)
         return true;
    
    return false;
}

bool Referee::isFriendlySquare(Board *b, Player *p, int square)
{
    char piece = b->getSquare(square);
    if (piece == EMPTY) return false;

    char powner = b->belongsTo(piece);
    char player = p->getPlayerNumber();

    if (powner == player)
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

bool Referee::movesAvailable(Board *b, Player *p, int numRolled)
{
    vector<char> playerPieces = p->getPlayerPieces();
    if (playerPieces.size() == 0) return false;

    int origin = 0;
    //for all player pieces in play currently
    for (char c : playerPieces)
    {
        origin = p->choosePiece(b, c);
        //if any move is legal
        if (validateMove(b, p, origin, numRolled) == INVALID)
            return true;
    }

    return false;
}