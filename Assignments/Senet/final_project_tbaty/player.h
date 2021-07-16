#ifndef __PLAYER_H__
#define __PLAYER_H__

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

        void initialize(bool player);

    public:
        Player(bool playerOne = true);
}



#endif //__PLAYER_H__