//uncomment next three lines for interactive debug
// #ifdef DEBUG
//   #define IDEBUG
//#endif

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

#include "player.h"
#include "board.h"
#include "referee.h"
#include "senet_constants.h"

using namespace std;

void displayInfo(Board *b, Player *p1, Player *p2, ostream& out = cout);
void shuffleBoard(Board *b);
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

    displayInfo(b, p1, p2);

    cout << "advancing pieces to new places" << endl 
         << "players taking 5 turns each" << endl
         << "bypassing referee validation" << endl;

    shuffleBoard(b);

    displayInfo(b, p1, p2);

    cout << "---- p1 turn" << endl;
    cout << "p1 rolls die" << endl;
    p1->rollDie(die);
    cout << "die: " << die << endl;
    cout << "p1 choose piece" << endl;
    char piece;
    cin >> piece;
    int origin = p1->choosePiece(b, piece);
    int target = r->validateMove(b, p1, origin, die);
    while (origin == INVALID || target == INVALID)
    {
        cout << "invalid choice; please try again" << endl;
        cout << "p1 choose piece" << endl;
        cin >> piece;
        origin = p1->choosePiece(b, piece);
        if (origin == INVALID)
            continue;

        cout << "\treferee validating p1 move \'" << piece << "\' "
             << "sq" << origin << " to sq";
        target = r->validateMove(b, p1, origin, die);
        target == INVALID ? cout << "INVALID" : cout << target;
        cout << endl;
        if (target == INVALID)
        {
            continue;
        }
        else
            break;
    }

    cout << "target: " << target << endl;
    p1->movePiece(b, origin, target);

    displayInfo(b, p1, p2);

    cout << "------ testing roll again behavior" << endl;
    cout << "new board" << endl;
    delete b;
    b = new Board();
    
    cout << "shuffling board" << endl;
    shuffleBoard(b);
    b->display();

    /*
     * during gameplay, the condition to terminate the loop will be when
     * r->isWinner() evaluates to true
     */
    bool done = false;
    bool playerOneTurn = true;
    while (!done)
    {
        //alternating turns
        playerOneTurn ? playTurn(b, r, p1)
                      : playTurn(b, r, p2);

        //swapping out for alternation
        playerOneTurn = !playerOneTurn;

        displayInfo(b, p1, p2);
        
        //play until first point is scored
        //check for winner
        if (p1->getScore() == 1 || p2->getScore() == 1)
            done = true;
    }

    delete b;
    delete r;
    delete p1;
    delete p2;

    return 0;
}

void displayInfo(Board *b, Player *p1, Player *p2, ostream& out)
{
    b->display();
    cout << "player pieces" << endl;
    p1->displayPieces();
    cout << endl;
    p2->displayPieces();
    cout << endl;

}

//pass it a new Board instance
void shuffleBoard(Board *b)
{
    Player *p1 = new Player(P1);
    Player *p2 = new Player(P2);

    int die;
    
    int origin, target;
    for (int i = 4; i >= 0; i--)
    {
        p1->rollDie(die);
        origin = 2 * i + 1;
        target = origin + die;

        p1->movePiece(b, origin, target);

        p2->rollDie(die);
        origin = 2 * i + 1;
        target = origin + die;

        p2->movePiece(b, origin, target);

    }

    delete p1;
    delete p2;
}

void playTurn(Board *b, Referee *r, Player *p)
{
    int die;
    bool rollAgain = true;

    while (rollAgain)
    {
        //player rolls die
        p->rollDie(die);
        cout << "die: " << die << endl;

        //ref checks whether to roll again
        rollAgain = r->rollAgain(die);

        //player selects piece
        char piece;
        int origin, target;

        //ref validates move
        do
        {
            //player selects piece
            if (origin == INVALID || target == INVALID) cout << "invalid selection" << endl;
            
            p->displayPieces();
            cout << endl;

            p->getPlayerNumber() == P1
                ? cout << "p1 choose piece: "
                : cout << "p2 choose piece: ";
            cin >> piece;
            origin = p->choosePiece(b, piece);
            cout << endl;

            target = r->validateMove(b, p, origin, die);
        }
        while (origin == INVALID || target == INVALID);

        p->movePiece(b, origin, target);
        b->display();
        if (p->getScore() == 1)
            break;
        
    }

}
