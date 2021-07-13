//uncomment for "Interactive Debug"
// #define IDEBUG

#include <iostream>

#include "player.h"
#include "board.h"

using namespace std;

int main()
{
    cout << "========== Player Tests ==========" << endl << endl;
    Player player;

    int row, col;
    row = 9;
    col = 1;

    cout << "Player functions:" << endl
         << "\tchoose player piece (9, 1): " << player.choosePiece(row, col) << endl;

    row = 8;
    col = 5;
    cout << "\tchoose obstacle piece (8, 5): " << player.choosePiece(row, col) << endl;

    row = 0;
    col = 4;
    cout << "\tchoose goal piece (0, 4): " << player.choosePiece(row, col) << endl;

    row = 0;
    col = 0;
    cout << "\tchoose empty square (0, 0): " << player.choosePiece(row, col) << endl;

    #ifdef IDEBUG
        cout << "enter selection (ex. 2 5): ";
        cin >> row >> col;
        while (!player.choosePiece(row, col))
        {
            cout << "invalid selection; please try again" << endl;
            cout << "enter selection (ex. 2 5): ";
            cin >> row >> col;
        }

        cout << "valid choice selection" << endl;
    #endif

    cout << "does the player have pieces remaining? ";
    player.hasPieces() ? cout << "Yes" << endl
                      : cout << "No" << endl;
    cout << "player has " << player.getNumRemainingPieces() << " remaining pieces" << endl;

    cout << "clearing pieces from board" << endl;
    while (player.hasPieces())
    {
        player.clearPiece();
        cout << "\tplayer has " << player.getNumRemainingPieces() << " remaining pieces" << endl;
    }

    cout << "does the player have pieces remaining? ";
    player.hasPieces() ? cout << "Yes" << endl
                      : cout << "No" << endl;

    cout << "=== new game ===" << endl;
    Player newplayer = Player(new Board());//default Board constrcutor; default numPieces, numTurns
    cout << "newplayer info:" << endl
         << "\tnumPieces: " << newplayer.getNumRemainingPieces() << endl
         << "\tnumTurns: " << newplayer.getNumTurns() << endl;
    
    for (int i = 0; i < 10; i++) newplayer.finishTurn();
    cout << "newplayer finished 10 turns; no pieces cleared" << endl;
    cout << "newplayer numTurns: " << newplayer.getNumTurns() << endl;

    return 0;
}
