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
    //seed srand
    srand(time(NULL));

    //game setup
    Board *b = new Board();
    int die = 2;
    Referee *r = new Referee();

    Player *p1 = new Player(P1);//P1 referenced in 'senet_constants.h'
    Player *p2 = new Player(P2);//P2 referenced in 'senet_constants.h'

    //arrange board
    b->setSquare(0, A);
    b->setSquare(1, ONE);
    b->setSquare(2, B);
    b->setSquare(3, EMPTY);
    b->setSquare(4, C);
    b->setSquare(5, EMPTY);
    b->setSquare(6, TWO);
    b->setSquare(7, THREE);
    b->setSquare(8, E);
    b->setSquare(9, D);
    b->setSquare(10, FIVE);
    b->setSquare(11, FOUR);

    cout << "------ initial conditions -----" << endl;
    b->display();
    cout << "die: " << die << endl;

    cout << "p2: any moves possible? (expect N): ";
    r->movesAvailable(b, p2, die) ? cout << "Y" << endl
                                  : cout << "N" << endl;

    playTurn(b, r, p2);

    cout << "p1 moves FOUR to sq12" << endl;
    p1->movePiece(b, 11, 12);
    b->display();

    cout << "p2: any moves possible? (expect Y): ";
    r->movesAvailable(b, p2, die) ? cout << "Y" << endl
                                  : cout << "N" << endl;

    playTurn(b, r, p2);


    delete b;
    delete r;
    delete p1;
    delete p2;

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
        {
            cout << "no moves available; rolling again" << endl;
            continue;
        }

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
            if (p->getPlayerNumber() == P2)
            {
                //ascii/char math - if piece is lowercase, convert to uppercase
                //so it matches P2 pieces in senet_constants.h
                if (piece > 96 && piece < 102)
                    piece -= ' ';
            }
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
