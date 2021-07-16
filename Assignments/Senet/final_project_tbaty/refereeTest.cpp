#include <iostream>

#include "referee.h"
#include "board.h"
#include "player.h"
#include "senet_constants.h"

using namespace std;

int main()
{
    cout << "---- Referee Tests -----" << endl;
    Board* b = new Board();
    Player* p1 = new Player();
    Player* p2 = new Player(false);

    Referee* r = new Referee();

    cout << "checking for winner;" << endl;
    bool done = false;
    char winner;
    while (!done)
    {
        p2->clearPiece(b, 100);//100 is dummy value; interested in decrementing numPieces
        winner = r->checkForWinner(b, p1, p2);
        #ifdef DEBUG
            p2->hasPieces() ? cout << "p2 still has pieces" << endl
                           : cout << "p2 has no pieces" << endl;
        #endif

        done = winner != EMPTY;
        if (done)
        {
            r->announceWinnner(winner);
        }
    }


    return 0;
}
