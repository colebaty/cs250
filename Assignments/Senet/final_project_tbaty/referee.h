#ifndef __REFEREE_H__
#define __REFEREE_H__

#include <iostream> 

#include "board.h"
#include "player.h"
#include "senet_constants.h"

class Referee
{
    private:
        char _winner;

        void setWinner(char winner);

        /**
         * @brief called only in the special case that a player's piece lands
         * on the trap square.  since the trap square behavior is governed by
         * the referee, and since capture is not possible during a trap move,
         * supplying the board is sufficient. reference squares are implied 
         * in a trap move, and their definitions are supplied in senet_constants.h
         * 
         * @param b 
         * @param square 
         */
        void findLanding(Board *b, int& square);


    public:
        Referee();
    
        bool isFriendlySquare(Board *b, Player *p, int square);
        /**
         * @brief returns true if _winner != EMPTY. Assumes _winner is only set
         * to P1 or P2
         * 
         * @return true 
         * @return false 
         */
        bool isWinner();

        /**
         * @brief Called at the end of each turn. Sets _winner to P1 or P2, whichever
         * is first to clear all pieces from the board. Returns EMPTY if no winner
         * found.
         * 
         * @param b 
         * @param p1 
         * @param p2 
         * @return char EMPTY if no winner found; otherwise P1 or P2, whichever is 
         * to clear all pieces from board
         */
        char checkForWinner(Board* b, Player* p1, Player* p2);

        void announceWinnner(std::ostream& out = std::cout);

        /**
         * @brief returns INVALID if no move possible. otherwise, returns
         * the index of the target square. governs trap square behavior.
         * 
         * @param b 
         * @param p 
         * @param origin 
         * @param numRolled 
         * @return int 
         */
        int validateMove(Board *b, Player *p, int origin, int numRolled);

        /**
         * @brief if Player rolls a 1, 4, or 5, they roll again after moving their
         * piece
         * 
         * @param die 
         * @return true the player rolls again
         * @return false 
         */
        bool rollAgain(const int& die);

        /**
         * @brief determines whether the given square is protected. returns true
         * when the square's forward or rear neighbor is occupied by a piece 
         * belonging to the same set of pieces.
         * 
         * @param b 
         * @param target 
         * @return true the square is protected
         * @return false 
         */
        bool isProtected(Board *b, const int& target);

        /**
         * @brief determines whether the given player has any legal moves
         * to play on the board - board may reach a state where all possible
         * target squares are unavailable. if no moves, player should roll again
         * 
         * @param b 
         * @param p 
         * @param numRolled 
         * @return true any player piece has a legal move
         * @return false no player piece has a legal move
         */
        bool movesAvailable(Board *b, Player *p, int numRolled);

};


#endif //__REFEREE_H__