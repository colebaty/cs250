//uncomment for "Interactive Debug"
#define IDEBUG

// uncomment for player tests
// #define PDBG

// uncomment for board tests
#define BDBG

//uncomment to show the board
#define SHOWBOARD

#include <iostream>

#include "player.h"
#include "board.h"

using namespace std;

int main()
{
    #ifdef IDEBUG
        cout << "interactive debug enabled" << endl;
    #endif

    #ifdef PDBG
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
    #endif

    #ifdef BDBG
        cout << "========== Board Tests ==========" << endl << endl;
        Board board;

        cout << "new board created:" << endl
             << "\ttests constructor, setSquare" << endl;
        board.displayBoard();
        cout << "tests getSquare()" << endl;
        cout << endl << "tests for invalid moves: expecting \'0\'" << endl
             << "\tO-piece (9, 1) off board:\t\t" << board.movePiece(PLAYER, 9, 1, DOWN) << endl
             << "\tO-piece (9, 3) to occupied square:\t" << board.movePiece(PLAYER, 9, 3, UP) << endl
             << "\tX-piece (0, 3) off board:\t\t" << board.movePiece(OBSTACLE, 0, 3, UP) << endl
             << "\tX-piece (0, 6) to occupied square:\t" << board.movePiece(OBSTACLE, 0, 6, LEFT) << endl;

        cout << "adding O-piece to (9, 0)" << endl;
        board.setSquare(PLAYER, 9, 0);
        #ifdef SHOWBOARD
            board.displayBoard();
        #endif
        cout << "attempting to move piece off board to left; expect \'0\': "
             << board.movePiece(PLAYER, 9, 0, LEFT) << endl;
        cout << "adding X-piece to (7, 9)" << endl;
        board.setSquare(OBSTACLE, 7, 9);
        #ifdef SHOWBOARD
            board.displayBoard();
        #endif
        cout << "attempting to move piece off board to right; expect \'0\': " 
             << board.movePiece(OBSTACLE, 7, 9, RIGHT) << endl;
        
        cout << "moving O@(9, 0) UP; expect 'O': " 
             << board.movePiece(PLAYER, 9, 0, UP) << endl;

        #ifdef SHOWBOARD
            board.displayBoard();
        #endif

        cout << "setting new piece O@(9, 4)" << endl;
        board.setSquare(PLAYER, 9, 4);
        #ifdef SHOWBOARD
            board.displayBoard();
        #endif

        #ifdef IDEBUG
            cout << "interactive debug enabled" << endl
                 << "select a piece ";
                
            int row, col;
            char dir;

            cin >> row >> col;

            cout << "direction to move (w a s d): ";
            cin >> dir;
            cout << endl;

            while (board.movePiece(PLAYER, row, col, dir) != INVALID)
            {
                #ifdef SHOWBOARD
                    board.displayBoard();
                #endif
                cout << "select a piece ";
                cin >> row >> col;
                cout << endl;

                cout << "direction to move (w a s d): ";
                cin >> dir;
                cout << endl;
            }

        #endif


    #endif

    return 0;
}
