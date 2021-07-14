#ifndef __BOARD_H__
#define __BOARD_H__

enum Direction : char {UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'};
enum Piece : char { PLAYER = 'O', OBSTACLE = 'X', EMPTY = ' ', 
                    GOAL = 'G', INVALID = '0'};

#include <iostream>

class Board
{
    private:
        char _board[10][10];//row, column

        /**
         * @brief recursively search in the indicated direction until an obstacle
         * is encountered (O- or X-piece). Set values of parameter to square 
         * immediately adjacent to obstacle.
         * 
         * Assumes all valid neighboring squares are free before being called.
         * 
         * Called only for PLAYER pieces.
         * 
         * @param row 
         * @param col 
         * @param dir 
         */
        void findTarget(int& row, int& col, char dir);

        /**
         * @brief Checks whether the neighbor imediately adjacent to the origin is 
         * free. Generally, for all pieces, "free" means the target square is on the board
         * and unoccupied.  For O-pieces, the target square is unoccupied if 
         * it is EMPTY or has a G-piece on it.
         * 
         * @param piece 
         * @param row 
         * @param col 
         * @param dir 
         * @return true 
         * @return false 
         */
        bool isNeighborFree(char piece, int row, int col, char dir);

    public:
        Board();

        /**
         * @brief sets up the board according to the layout in the assignment
         * instructions:
         * O-pieces at (9, [1, 3, 5, 7])
         * X-pieces at (8, [1, 3, 5, 7]), (3, [3, 6]), (0, [3, 6])
         * G-pieces at (0, 4-5)
         * 
         */
        void initialize();

        /**
         * @brief Prints the board to the specified ostream (default is cout)
         * 
         * @param out 
         */
        void displayBoard(std::ostream& out=std::cout);
        
        /**
         * @brief returns the piece at the specified square
         * 
         * @param row 
         * @param col 
         * @return char from Piece enum type
         */
        char getSquare(int row, int col);

        /**
         * @brief Set the indicated square to the desired piece. Assumes
         * isValidMove() returns true, Player::choosePiece() returns true
         * 
         * @param piece 
         * @param row 
         * @param col 
         */
        void setSquare(char piece, int row, int col);
        bool isValidMove(char piece, int row, int col, char dir);

        /**
         * @brief Move the piece at the indicated square (origin) in the desired direction.
         * If an O-Piece, move until obstacle (X-piece or another O-piece), or 
         * until goal; set piece at the space immediately adjacent to obstacle (target).
         * If an X-piece, move one square, provided target square is not already occupied by any other piece.
         * 
         * Target squares must be on the board.
         * 
         * If the move is valid, swap the values of the origin and target squares.
         * 
         * Returns '0' if the move is invalid; otherwise, returns the value of the 
         * target square - i.e. if target square is G-piece, we need to know so 
         * we can clear the piece off the board and adjust accordingly.
         * 
         * Assumes piece selection has been validated by Player::isValidSelection().
         * 
         * @param piece 
         * @param row 
         * @param col 
         * @param dir 
         * @return '0' if the move is invalid; the value of the updated target square otherwise
         */
        char movePiece(char piece, int row, int col, char dir);

};


#endif //__BOARD_H__