#ifndef __BOARD_H__
#define __BOARD_H__

enum PlayerOnePiece : char {ONE = '1', TWO = '2', THREE = '3', FOUR = '4', FIVE = '5'};
enum PlayerTwoPiece : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E'};
enum Trap : int {TRAP = 27, LANDING = 15};

const char TRAP_PIECE = 'X';
const char EMPTY = ' ';
const char INVALID = '0';

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
        char setSquare(int& square, char piece);

        /**
         * @brief determines whether a piece belongs to Player 1. Assumes you're 
         * only passing it Player piece enum types.
         * 
         * @param piece 
         * @return true piece belongs to Player 1
         * @return false pice belongs to Player 2
         */
        bool belongsTo(char piece);

};


#endif //__BOARD_H__