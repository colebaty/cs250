#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "board.h"
#include "senet_constants.h"

class Player
{
    private:
        /**
         * @brief if true, this is Player One, and their pieces are PlayerOne 
         * enum types; Player Two applies otherwise.
         * 
         */
        bool _playerOne;
        int _numPieces;

    public:
        Player();
        /**
         * @brief Construct a new Player object.  The only way to set a Player
         * Two object is to explicitly call this constructor with 'false'
         * 
         * @param playerOne 
         */
        Player(bool playerOne);

        /**
         * @brief permits the player instance to identify itself as either
         * Player One or Player Two
         * 
         * @return true if this instance is Player One
         * @return false if this instsance is Player Two
         */
        bool isPlayerOne() { return _playerOne == true; };

        /**
         * @brief sets the value of die to an integer on [1, 5]. die must be 
         * declared in main and is passed to each player.
         * 
         * @param die 
         */
        void rollDie(int& die);

        /**
         * @brief moves the piece at the specified origin square according to
         * the number rolled on the die.  Assumes Referee::isValidMove() returns
         * true.
         * 
         * @param b 
         * @param square 
         * @param numRolled 
         * @return int the index of the target square
         */
        int movePiece(Board *b, int origin, int numRolled);

        /**
         * @brief returns true if _numPieces > 0
         * 
         * @return true numPieces > 0
         * @return false 
         */
        bool hasPieces() { return _numPieces > 0; };

        void clearPiece(Board *b, int square) { _numPieces--; };

};



#endif //__PLAYER_H__