#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "board.h"

class Player
{
    private:
        int _piecesOnBoard;
        int _numTurns;
        Board* _board;//interact with board through this reference

    public:
        Player();
        Player(Board *board);
        ~Player();

        /**
         * @brief initializes player data; if not otherwise specified, initializes 
         * the player's number of pieces to 4, the number of completed moves to 0.
         * 
         * @param board the board
         * @param numPieces the number of pieces; default is 4
         * @param numTurns the number of turns made; default is 0
         */
        void initialize(Board *board, int numPieces = 4, int numTurns = 0);

        /**
         * @brief determines whether a selected square is a valid choice: that is,
         * the chosen square is on the board, and contains either an O-Piece or an
         * X-Piece
         * 
         * @param row the row of the piece
         * @param col the column of the piece
         * @return true piece is on the board and is either an O-Piece or an X-Piece
         * @return false piece is not on the board or is not an O-Piece or is not an X-Piece
         */
        bool isValidSelection(int row, int col);

        /**
         * @brief select a piece on the board. returns false if the selected square
         * does not contain an O-piece or an X-piece
         * 
         * @param row 
         * @param col 
         * @return true if selection is valid
         * @return false if selection is valid
         */
        bool choosePiece(int& row, int& col);


        /**
         * @brief removes a piece from the board after it has reached a goal piece.
         * that is, decrements the number of available pieces
         * 
         */
        void clearPiece() { _piecesOnBoard--; };

        bool hasPieces() { return _piecesOnBoard > 0 && _piecesOnBoard < 5; };
        int getNumRemainingPieces() { return _piecesOnBoard; };

        /**
         * @brief increments the number of turns
         * 
         */
        void finishTurn() { _numTurns++; };

        int getNumTurns() { return _numTurns; };
};

#endif //__PLAYER_H__