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

    displayInfo(b, p1, p2);

    cout << "---- p1 turn" << endl;
    cout << "p1 rolls die" << endl;
    p1->rollDie(die);
    cout << "die: " << die << endl;
    cout << "p1 choose piece" << endl;
    char piece;
    cin >> piece;
    origin = p1->choosePiece(b, piece);
    target = origin + die;
    while (origin == INVALID || target == INVALID)
    {
        cout << "invalid choice; please try again" << endl;
        cout << "p1 choose piece" << endl;
        cin >> piece;
        origin = p1->choosePiece(b, piece);
        if (origin == INVALID)
            continue;

        cout << "\treferee validating p1 move \'" << piece << "\' "
             << "sq" << origin << " to sq" << target << endl;
        target = r->validateMove(b, p1, origin, die);
        if (target == INVALID)
        {
            continue;
        }
        else
            return target;
    }

    cout << "target: " << target << endl;
    p1->movePiece(b, origin, target);

    displayInfo(b, p1, p2);

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