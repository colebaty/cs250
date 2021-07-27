#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <fstream>

#include "player.h"
#include "board.h"
#include "referee.h"
#include "senet_constants.h"

using namespace std;

void printLine(ostream& out = cout);
void displayInfo(Board *b, Player *p1, Player *p2, ostream& out = cout);
void playGame(Board *b, Referee *r, Player *p1, Player *p2);
void playFirstTurn(Board *b, Referee *r, Player *p1);//p1 starts game and must play piece FIVE
void playTurn(Board *b, Referee *r, Player *p);

int main()
{
    //seed srand
    srand(time(NULL));

    //game setup
    Board *b = new Board();
    int die;
    Referee *r = new Referee();

    Player *p1 = new Player(P1);//P1 referenced in 'senet_constants.h'
    Player *p2 = new Player(P2);//P2 referenced in 'senet_constants.h'

    while (!r->isWinner())
    {
        playGame(b, r, p1, p2);
    }

    assert(r->isWinner());

    r->announceWinnner(cout);

    delete b;
    delete r;
    delete p1;
    delete p2;

    return 0;
}

void playGame(Board *b, Referee *r, Player *p1, Player *p2)
{
    //play first turn - P1 must play FIVE
    playFirstTurn(b, r, p1);

    displayInfo(b, p1, p2);

    bool playerOneTurn = false;//P1 has already played
    while (!r->isWinner())
    {
        //alternating turns
        playerOneTurn ? playTurn(b, r, p1)
                      : playTurn(b, r, p2);

        //swapping out for alternation
        playerOneTurn = !playerOneTurn;

        displayInfo(b, p1, p2);
        
        //check for winner
        r->checkForWinner(b, p1);
        r->checkForWinner(b, p2);
    }

}

void playFirstTurn(Board *b, Referee *r, Player *p1)//p1 starts game and must play piece FIVE
{
    int die;
    bool rollAgain = true;
    bool isFirstRoll = true;

    while (rollAgain)
    {
        //player rolls die
        p1->rollDie(die);

        //ref checks whether to roll again
        rollAgain = r->rollAgain(die);

        //player selects piece
        char piece;
        int origin = 9;//so we dont get an 'invalid selection' before any move has been made
        int target;

        //ref validates move
        do
        {
            //player selects piece
            if (isFirstRoll && (origin != 9 || target == INVALID)) 
                cout << "Invalid selection; please try again" << endl;
            else if (origin == INVALID || target == INVALID) 
                cout << "Invalid selection; please try again" << endl;
            
            b->display();
            cout << "Die: " << die;
            if (rollAgain)
                cout << " - roll again!";
            cout << endl;
            p1->displayPieces();
            cout << endl;

            cout << "Player One, please choose ";
            if (isFirstRoll)
                cout << "piece '5' to begin the game: ";
            else
                cout << "a piece: ";
            cin >> piece;
            origin = p1->choosePiece(b, piece);
            cout << endl;

            target = r->validateMove(b, p1, origin, die);
        }
        while ((isFirstRoll && (origin != 9 || target == INVALID)) ||
               (origin == INVALID || target == INVALID));

        p1->movePiece(b, origin, target);
        isFirstRoll = false;
    }
        
}

void playTurn(Board *b, Referee *r, Player *p)
{
    int die;
    bool rollAgain = true;

    while (rollAgain && !r->isWinner())
    {
        //player rolls die
        p->rollDie(die);

        //check for available moves
        if (!r->movesAvailable(b, p, die))
        {
            r->checkForWinner(b, p);
            cout << "No moves available - rolling again" << endl;
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
            origin = p->choosePiece(b, piece);
            cout << endl;

            target = r->validateMove(b, p, origin, die);
        }
        while (origin == INVALID || target == INVALID);

        p->movePiece(b, origin, target);
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

