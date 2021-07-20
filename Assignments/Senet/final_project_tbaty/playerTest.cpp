#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

#include "player.h"
#include "board.h"
// #include "referee.h"
#include "senet_constants.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    Player *p1 = new Player();
    Player *p2 = new Player(false);

    int die;
    cout << "p1 rolling die to initialize: ";
    p1->rollDie(die);
    cout << die << endl;

    cout << "p2 rolling die; expecting different number: ";
    p2->rollDie(die);
    cout << die << endl;

    /*
        testing that rollDie() returns numbers only on [1,5].
        elements of seive should sum to 100
    */
    int seive[5];
    for (int i = 0; i < 100; i++)
    {
        p1->rollDie(die);
        seive[die - 1]++;
    }

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "seive[" << i << "]: " << seive[i] << endl;
        sum += seive[i];
    }
    
    assert(sum == 100);
    
    /*
        todo: 
            [ ] update isPlayerOne() -> getPlayerNumber()
    */
    // cout << "p1 ";
    // p1->isPlayerOne() ? cout << "is"
    //                   : cout << "is not";
    // cout << " Player One" << endl;
     
    // cout << "p2 ";
    // p2->isPlayerOne() ? cout << "is not"
    //                   : cout << "is";
    // cout << " Player Two" << endl;

    cout << "----- Player Tests with Board -----" << endl;
    Board *b = new Board();

    b->display();
    cout << "p1 choosing square 1, expecting INVALID" << endl;
    int choice = p1->choosePiece(b, 1);
    assert(choice == INVALID);
    cout << "p1 unable to select square 1" << endl;

    cout << "p2 choosing square 1; expect INVALID" << endl;
    choice = p2->choosePiece(b, 1);
    assert(choice == INVALID);
    cout << "p2 unable to select square 1" << endl;

    cout << "p1 choosing square 9, expecting 9" << endl;
    choice = p1->choosePiece(b, 9);
    assert(choice == 9);
    cout << "p1 successfully selected piece at square 9" << endl;

    cout << "p2 choosing square 9, expecting INVALID" << endl;
    choice = p2->choosePiece(b, 9);
    assert (choice == INVALID);
    cout << "p2 unable to select piece at square 9" << endl;

    cout << "p2 choosing square 8, expecting INVALID" << endl;
    choice = p2->choosePiece(b, 8);
    assert (choice = INVALID);
    cout << "p2 unable to select piece at square 8" << endl;

    assert(p1->getScore() == 0);
    cout << "p1 score (expecting 0): " << p1->getScore() << endl;
    cout << "p1 moves piece at square 9 to FINISH square" << endl;
    p1->movePiece(b, 9, FINISH);
    assert(p1->getScore() == 1);
    cout << "p1 score (expecting 1): " << p1->getScore() << endl;

    b->display();




    delete b;
    delete p1;
    delete p2;
    
    return 0;
}
