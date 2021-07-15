#include <iostream>

#include "player.h"
#include "board.h"

using namespace std;

void printHeader(ostream& out = cout);
void printrules(ostream& out = cout);
void playGame(Player& p, Board* b);

int main()
{
    //play game until all pieces have been moved off board
    //setup
    //declare board, player
    Board *b = new Board();
    Player p = Player(b);

    //play game
    playGame(p, b);

    //wrap up
    cout << "Puzzle completed in " << p.getNumTurns() << " moves." << endl;
    
    return 0;
    //wrap-up
}

void playGame(Player& p, Board* b)
{
    printHeader();
    printrules();
    b->displayBoard();

    int row, col;
    //while not done (player.hasPieces())
    while (p.hasPieces())
    {
        //player selects piece
        cout << "Player, please choose a piece (ex. 2 1): ";
        cin >> row >> col;

        while (!p.choosePiece(row, col) || !cin)
        {
            if (!cin) 
            {
                cin.ignore('\n', 100);
                cin.clear();
            }
            cout << "Invalid selection, please try again." << endl;
            cout << "Player, please choose a piece (ex. 2 1): ";
            cin >> row >> col;
        }

        //player chooses direction to move piece
        char dir;

        cout << "                                                        | w | " << endl;
        cout << "Player, please choose which direction to move the piece |asd|:";

        cin >> dir;

        char result = p.movePiece(row, col, dir);
        while (result == INVALID || result == EMPTY || !cin)
        {
            if (!cin) 
            {
                cin.clear();
            }
            cout << "Invalid selection; please try again." << endl;
            cout << "                                                        | w | " << endl;
            cout << "Player, please choose which direction to move the piece |asd|:";

            cin >> dir;
            result = p.movePiece(row, col, dir);
        }

        b->displayBoard();
        p.finishTurn(result);
        cout << "Number of turns completed:\t" << p.getNumTurns() << endl
             << "Number of pieces remaining:\t" << p.getNumRemainingPieces() << endl
             << "-----------------------------------" << endl << endl;
    }

}

void printHeader(ostream& out)
{
    out << "***********************************" << endl;
    out << "******** Assg8 Puzzle Game ********" << endl;
    out << "***********************************" << endl;
}

void printrules(ostream& out)
{
    cout << "------------ Rules ---------------" << endl;

    cout << "Choose a piece on the board by selecting its grid coordinate (eg. 2 1)." << endl
         << "Next, choose the direction in which to move the piece (wasd)." << endl
         << "An O moves as many spaces possible until it meets an obstruction or " << endl
         << "a goal piece (indicated by G)." << endl
         << "An obstruction is:" << endl
         << "\t- any other piece except G" << endl
         << "\t- the edge of the board" << endl
         << "An X moves only one space in the desired direction, provided the " << endl
         << "target space is not occuped by any other piece." << endl
         << "Invalid piece selections or direction choices are not counted in " << endl
         << "the player's turn total." << endl
         << "When an O makes it to a G, it is cleared from the board. The game is " << endl
         << "won when there are no more O pieces remaining." << endl
         << "Try to win in as few moves as possible!" << endl;
    
    out << "----------------------------------" << endl << endl;
}