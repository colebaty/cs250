#ifndef __BOARD_H__
#define __BOARD_H__

enum Direction : char {UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'};
enum Piece : char { PLAYER = 'O', OBSTACLE = 'X', EMPTY = ' ', GOAL = 'G'};

#include <iostream>

class Board
{
    private:
        char _board[10][10];//row, column

    public:
        Board();

        void initialize();

        /**
         * @brief Prints the board to the specified ostream (default is cout)
         * 
         * @param out 
         */
        void displayBoard(std::ostream& out=std::cout);
        char getSquare(int row, int col);
        void setSquare(char piece, int row, int col);
        bool isValidMove(char piece, int row, int col, char dir);
        void movePiece(char piece, int row, int col, char dir);
};


#endif //__BOARD_H__