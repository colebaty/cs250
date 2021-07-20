#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "senet_constants.h"

class Board
{
    private:
        char _board[30];
        /**
         * @brief set the board up; put the players' pieces in starting posistions
         * and set all other squares to EMPTY or TRAP as needed.
         * 
         */
        void initialize();

        void printRow(std::ostream& out=std::cout);

    public:
        Board();

        /**
         * @brief Get the the value of the square at the given index
         * 
         * @param square 
         * @return char 
         */
        char getSquare(int square) { return _board[square]; };

        /**
         * @brief Places a piece at the indicated square.  If capture is possible,
         * executes capture.
         * 
         * @param square 
         * @param piece 
         * @return INVALID if a piece may not be set at the square; the value of 
         * the square in all other cases;
         */
        char setSquare(const int& square, char piece, bool capture = false);

        /**
         * @brief determines whether a piece belongs to Player 1. Assumes you're 
         * only passing it Player piece enum types.
         * 
         * @param piece 
         * @return P1 or P2
         */
        char belongsTo(char piece);

        void swap(int a, int b);

        void display(std::ostream& out=std::cout);

};


#endif //__BOARD_H__