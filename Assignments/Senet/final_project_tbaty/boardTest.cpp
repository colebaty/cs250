#define CONST
#include <iostream>
#include "board.h"
#include "senet_constants.h"

using namespace std;

int main()
{
    //test constant access
    #ifdef CONST
        cout << "\tONE: " << ONE << endl
             << "\tTWO: " << TWO << endl
             << "\tTHREE: " << THREE << endl
             << "\tFOUR: " << FOUR << endl
             << "\tFIVE: " << FIVE << endl;
    #endif

    /*
        Declare/instantiate new board.  Implicit calls to these functions;
            - initialize()
                - setSquare()
    */
    Board b;

    /*
        Implicit call to getSquare().  
    */
    b.display();

    return 0;
}
