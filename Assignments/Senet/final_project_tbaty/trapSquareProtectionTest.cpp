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
void displayInfo(Board *b, Player *p1, Player *p2, ostream& out = cout);
void playGame(Board *b, Referee *r, Player *p1, Player *p2);

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

    cout << "----- trap square protection test -----" << endl;

    //arrange board
    cout << "arranging board so an unprotected piece is ahead of TRAP" << endl;

    cout << "p1 moving FIVE to TRAP - 1" << endl;
    p1->movePiece(b, 9, TRAP - 1);
    displayInfo(b, p1, p2);

    cout << "test whether square TRAP - 1 is protected: ";
    assert(!r->isProtected(b, TRAP - 1));
    cout << "N" << endl;

    cout << "test whether p2 piece E can caputure p1 piece FIVE @ sqaure TRAP - 1: ";
    int target = r->validateMove(b, p2, 8, (TRAP - 1) - 8);
    cout << "Y" << endl;

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

void displayInfo(Board *b, Player *p1, Player *p2, ostream& out)
{
    b->display();
    out << "Score: " << endl
        << "\tPlayer One: " << p1->getScore()
        << "\t Player Two: " << p2->getScore()
        << endl;

}

void playGame(Board *b, Referee *r, Player *p1, Player *p2)
{

    bool done = false;
    bool playerOneTurn = true;
    char winner = EMPTY;
    while (!done)
    {
        //alternating turns
        playerOneTurn ? playTurn(b, r, p1)
                      : playTurn(b, r, p2);

        //swapping out for alternation
        playerOneTurn = !playerOneTurn;

        displayInfo(b, p1, p2);
        
        //check for winner
        winner = r->checkForWinner(b, p1, p2);

        if (winner != EMPTY)
            done = true;
    }

}

