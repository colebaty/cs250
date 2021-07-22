#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

#include "player.h"
#include "board.h"
#include "referee.h"
#include "senet_constants.h"


using namespace std;

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

    cout << "p2: any moves possible? ";
    r->movesAvailable(b, p2, die) ? cout << "Y" << endl
                                  : cout << "N" << endl;

    delete b;
    delete r;
    delete p1;
    delete p2;

    return 0;
}
