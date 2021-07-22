#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>

#include "board.h"
#include "senet_constants.h"

class Player
{
    private:
        char _playerNumber;
        int _score;
        char _playerPieces[5];

        // bool isProtected(Board *b, int square);

        /**
         * @brief called after a piece reaches FINISH. 
         * clears piece from board. decrements score.
         * 
         * @param b 
         * @param square 
         */
        void clearPiece(Board *b, int square);

        bool isInPlay(char piece0);

    public:
        Player();

        /**
         * @brief Construct a new Player object
         * 
         * @param playerNumber 
         */
        Player(char playerNumber);

        /**
         * @brief Set the Player object to specified player number. Permitted
         * values are P1 or P2, which are defined in senet_constants.h. Initializes
         * pieces to specified player pieces.
         * 
         * @param playerNumber 
         */
        void setPlayer(char playerNumber);

        /**
         * @brief permits the player instance to identify itself as either
         * Player One or Player Two
         * 
         * @return P1 or P2
         */
        char getPlayerNumber() { return _playerNumber; };

        /**
         * @brief sets the value of die to an integer on [1, 5]. die must be 
         * declared in main and is passed to each player.
         * 
         * @param die 
         */
        void rollDie(int& die);

        /**
         * @brief returns INVALID unless player selects one of player's own pieces
         * stll remaining on board. returns square location otherwise;
         * 
         * @param square 
         * @return int 
         */
        int choosePiece(Board *b, char piece);

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
        void movePiece(Board *b, int origin, int target, char mode = ADVANCE);

        /**
         * @brief returns true if _score < 5
         * 
         * @return true score < 5
         * @return false 
         */
        bool hasPieces() { return _score < 5; };

        /**
         * @brief displays this player's pieces. neither prepends nor appends
         * any whitespace, to include leading space or newline.
         * 
         * @param out 
         */
        void displayPieces(std::ostream& out = std::cout);

        /**
         * @brief returns the Player's score
         * 
         * @return int 
         */
        int getScore() { return _score; };

        /**
         * @brief returns a dynamically allocated array of the player's available
         * pieces at the moment the function is called. primarily for use within 
         * Referee::movesAvailable()
         * 
         * @return char* 
         */
        std::vector<char> getPlayerPieces();

};



#endif //__PLAYER_H__