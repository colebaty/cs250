#ifndef __REFEREE_H__
#define __REFEREE_H__

#include <iostream> 

#include "senet_constants.h"
#include "player.h"
#include "board.h"

class Referee
{
    private:
        Board* _b;
        Player* _p1;
        Player* _p2;

    public:
        Referee();
        Referee(Board* b = nullptr, Player* p1 = nullptr, Player* p2 = nullptr);
        ~Referee();
    
        bool isFriendlySquare(int square, bool playerOne);
        void initialize(Board* b, Player* p1, Player* p2);
        void announceWinnner(char winner, std::ostream& out = std::cout);

};


#endif //__REFEREE_H__