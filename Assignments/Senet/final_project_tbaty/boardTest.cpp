//uncomment to test access to constant header file
// #define CONST

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

    /*
        testing belongsTo()
    */
    cout << "getting piece at square 5 (zero-indexed, expecting '3': ";
    char piece = b.getSquare(5);
    cout << piece << endl;

    cout << "piece at square 5 belongs to (expecting 1): Player ";
    b.belongsTo(piece) ? cout << 1 << endl
                       : cout << 2 << endl;
    
    cout << "getting piece at square 4 (expecting 'C': ";
    piece = b.getSquare(4);
    cout << piece << endl;

    cout << "piece at square 4 belongs to (expecting 2): Player ";
    b.belongsTo(piece) ? cout << 1 << endl
                       : cout << 2 << endl;
    
    /*
        testing swap()
    */

   cout << "swapping square 5 for square 4" << endl;
   b.swap(5, 4);
   b.display();

    return 0;
}
