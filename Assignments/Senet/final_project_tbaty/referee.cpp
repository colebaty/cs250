#include "board.h"
#include "player.h"
#include "referee.h"
#include "senet_constants.h"

using namespace std;

Referee::Referee()
{
    _b = nullptr;
    _p1 = nullptr;
    _p2 = nullptr;
}

Referee::Referee(Board* b, Player* p1, Player* p2)
{
    initialize(b, p1, p2);
}

Referee::~Referee()
{
    delete _b;
    delete _p1;
    delete _p2;
}

void Referee::initialize(Board* b, Player* p1, Player* p2)
{
    _b = b;
    _p1 = p1;
    _p2 = p2;
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
    out << "wins!";
}