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
    Player* p1 = new Player(P1);
    Player* p2 = new Player(P2);

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

        cout << "p1 available pieces: ";
        p1->displayPieces();
        cout << "\t\t p1 score: " << p1->getScore() << endl;

        cout << "p2 available pieces: ";
        p2->displayPieces();
        cout << "\t\t p2 score: " << p2->getScore() << endl;

        done = winner != EMPTY;
        if (done)
       {
            r->announceWinnner(winner);
        }
        
        i -= 2;
    }

    cout << "-------- testing land exactly on FINISH to clear piece" << endl;
    //reset board, p1
    delete b;
    b = new Board();
    
    delete p1;
    p1 = new Player(P1);

    cout << "referee validating p1 moving exactly from origin square to FINISH" << endl
         << "\texpecting FINISH: " << r->validateMove(b, p1, 9, FINISH - 9)
         << "\tFINISH: " << FINISH << endl;
    
    cout << "p1 score; expecting 0: " << p1->getScore() << endl;
    cout << "p1 moving sq9->FINISH" << endl;
    p1->movePiece(b, 9, FINISH);
    cout << "p1 score; expecting 1: " << p1->getScore() << endl;
    b->display();
    cout << "player pieces" << endl;
    p1->displayPieces();
    cout << endl;
    p2->displayPieces();
    cout << endl;


    cout << "-------- testing capture/protection" << endl;
    cout << "new board" << endl;
    delete b;
    b = new Board();
    b->display();
    cout << "arranging pieces" << endl;
    p1->movePiece(b, 9, 18);
    p1->movePiece(b, 7, 17);
    b->display();
    cout << "player pieces" << endl;
    p1->displayPieces();
    cout << endl;
    p2->displayPieces();
    cout << endl;


    cout << "p2 attempting to capture protected squares 17 and 18 with piece E" << endl;
    cout << "referee validating move to sq 17; expecting INVALID: " 
         << r->validateMove(b, p2, 8, 9) - '0' << endl
         << "\tINVALID: " << INVALID << endl;
    cout << "referee validating move to sq 18; expecting INVALID: " 
         << r->validateMove(b, p2, 8, 10) - '0' << endl
         << "\tINVALID: " << INVALID << endl;
    
    cout << "p1 moving piece '5' ahead one space" << endl;
    p1->movePiece(b, 18, 19);
    b->display();
    cout << "player pieces" << endl;
    p1->displayPieces();
    cout << endl;
    p2->displayPieces();
    cout << endl;



    cout << "p2 attempting to capture unprotected squares 17 and 19 with piece E" << endl;
    cout << "referee validating p2 move piece E to sq 17; expecting 17: ";
    assert(r->validateMove(b, p2, 8, 9) == 17);
    cout << r->validateMove(b, p2, 8, 9) << endl;
    cout << "p2 moving piece E to sq17" << endl;
    p2->movePiece(b, 8, 17);
    b->display();
    cout << "player pieces" << endl;
    p1->displayPieces();
    cout << endl;
    p2->displayPieces();
    cout << endl;
    cout << "p2 movinr piece E to sq19" << endl;
    p2->movePiece(b, 17, 19);
    b->display();
    cout << "player pieces" << endl;
    p1->displayPieces();
    cout << endl;
    p2->displayPieces();
    cout << endl;
    
    


    delete b, r, p1, p2;

    return 0;
}
