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

        void setWinner(char& winner);

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

        void announceWinnner(char winner, std::ostream& out = std::cout);

        /**
         * @brief returns INVALID if no move possible. otherwise, returns
         * the index of the target square. governs trap square behavior, as well
         * as dice roll values which enable the player to roll again.
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


};


#endif //__REFEREE_H__