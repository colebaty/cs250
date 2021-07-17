#include <iostream>
#include <ctime>
#include <random>
#include <cassert>

#include "player.h"
#include "board.h"

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
    
    cout << "p1 ";
    p1->isPlayerOne() ? cout << "is"
                      : cout << "is not";
    cout << " Player One" << endl;
     
    cout << "p2 ";
    p2->isPlayerOne() ? cout << "is not"
                      : cout << "is";
    cout << " Player Two" << endl;

    cout << "----- Player Tests with Board -----" << endl;
    
    return 0;
}
