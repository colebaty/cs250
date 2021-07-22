#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

#include "player.h"
#include "board.h"
#include "referee.h"
#include "senet_constants.h"


using namespace std;

void playTurn(Board *b, Referee *r, Player *p);

int main()
{
    return 0;
}

void playTurn(Board *b, Referee *r, Player *p)
{
    int die;
    bool rollAgain = true;

    while (rollAgain)
    {
        //player rolls die
        p->rollDie(die);

        //check for available moves
        if (!r->movesAvailable(b, p, die))
            continue;

        //ref checks whether to roll again
        rollAgain = r->rollAgain(die);

        //player selects piece
        char piece;
        int origin, target;

        //ref validates move
        do
        {
            //player selects piece
            if (origin == INVALID || target == INVALID) 
                cout << "Invalid selection; please try again." << endl;
            
            b->display();
            cout << "Die: " << die;
            if (rollAgain)
                cout << " - roll again!";
            cout << endl;
            p->displayPieces();
            cout << endl;

            p->getPlayerNumber() == P1
                ? cout << "Player 1"
                : cout << "Player 2";
            cout <<  ", please choose a piece: ";
            cin >> piece;
            //account for lowercase piece entry for P2
            origin = p->choosePiece(b, piece);
            cout << endl;

            target = r->validateMove(b, p, origin, die);
        }
        while (origin == INVALID || target == INVALID);

        p->movePiece(b, origin, target);
        // b->display();
        if (r->isWinner())
            break;
        
    }

}
