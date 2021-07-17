// #include "board.h"
// #include "player.h"
#include "referee.h"
// #include "senet_constants.h"

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

//stub
 char Referee::validateMove(Board *b, Player *p, int& origin, int& target)
 {
     //if target not empty
        
     return INVALID;
 }

 bool Referee::isFriendlySquare(Board *b, Player *p, int square)
 {
     bool playerOne = p->isPlayerOne();
     char piece = b->getSquare(square);

     if (b->belongsTo(piece) == playerOne)
        return true;
    
    return false;
 }