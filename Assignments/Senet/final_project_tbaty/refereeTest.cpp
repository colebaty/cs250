#include <iostream>
#include <cassert>

#include "referee.h"
#include "board.h"
#include "player.h"
#include "senet_constants.h"

using namespace std;

int main()
{
    cout << "---- Referee Tests -----" << endl;
    Board* b = new Board();
    Player* p1 = new Player();
    Player* p2 = new Player(false);

    Referee* r = new Referee();

    cout << "testing for friendlies" << endl;
    b->display();
    assert(r->isFriendlySquare(b, p1, 1));//p1 pieces start on odd squares
    cout << "board[1]";
    r->isFriendlySquare(b, p1, 1) ? cout << " is "
                                  : cout << " is not ";
    cout << "friendly to p1" << endl;

    assert(!r->isFriendlySquare(b, p1, 2));//p2 pieces start on even squares
    cout << "board[2]";
    r->isFriendlySquare(b, p1, 2) ? cout << " is "
                                  : cout << " is not ";
    cout << "friendly to p1" << endl;

    cout << "testing validateMove() functionality" << endl;
    cout << "validate p1 move sq 9 [1, 5] squares forward" << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << "\texpect 9 + ";
        i == 5 ? cout << "6" : cout << i;
        cout << ": " << r->validateMove(b, p1, 9, i) << endl;
    }

    cout << "validate moving p1sq9 to sq12; expect 12: ";
    cout << r->validateMove(b, p1, 9, 3) << endl;
    cout << "p1 moving sq9 to sq12" << endl;
    p1->movePiece(b, 9, 12);
    b->display();
    cout << "validate moving p2sq8 to sq12; expect 12 (capture/swap): ";
    cout << r->validateMove(b, p2, 8, 4) << endl;
    cout << "p2 moving sq8 to sq12" << endl;
    p2->movePiece(b, 8, 12);
    b->display();
    cout << "validate moving p1sq7 sq8; expect INVALID (occupied - friendly): ";
    cout << r->validateMove(b, p1, 7, 1) - '0' << endl;//char math due to different return types
    cout << "INVALID: " << INVALID << endl;
    b->display();

    cout << "---- testing trap square behavior" << endl;
    cout << "ref validates p2sq12->trap square; expecting LANDING: ";
    int target = r->validateMove(b, p2, 12, TRAP - 12);
    assert(target == LANDING);
    cout << target << endl;
    cout << "p2 moves sq12->trap" << endl;
    p2->movePiece(b, 12, target);
    b->display();

    cout << "ref validates p1sq8->trap square; expecting LANDING + 1: ";
    target = r->validateMove(b, p1, 8, TRAP - 8);
    // assert(target == LANDING + 1);
    cout << target << endl;
    cout << "p1 moves sq8->trap" << endl;
    p2->movePiece(b, 8, target);
    b->display();

    cout << "testing moving p2 piece off LANDING; expect sq14 to display LANDING_PIECE" << endl;
    p2->movePiece(b, LANDING, LANDING + 3);
    b->display();


    cout << "--- testing endgame, finding winner" << endl;
    cout << "testing moving player pieces to FINISH, clear pieces" << endl;
    //reset board
    delete b;
    b = new Board();

    bool done = false;
    char winner;
    int i = 9;
    while (!done)
    {
        p1->movePiece(b, i, FINISH);
        b->display();
        winner = r->checkForWinner(b, p1, p2);
        #ifdef DEBUG
            p1->hasPieces() ? cout << "p1 still has pieces" << endl
                           : cout << "p1 has no pieces" << endl;
        #endif

        done = winner != EMPTY;
        if (done)
        {
            r->announceWinnner(winner);
        }
        
        i -= 2;
    }

    return 0;
}
