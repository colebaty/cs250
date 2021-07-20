#ifndef __SENET_CONSTANTS_H__
#define __SENET_CONSTANTS_H__

enum PlayerOnePieces : char {ONE = '1', TWO = '2', THREE = '3', FOUR = '4', FIVE = '5'};
enum PlayerTwoPieces : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E'};
enum SpecialSquares : int {TRAP = 26, LANDING = 14, FINISH = 29};
enum SpecialPieces : char {TRAP_PIECE = 'X', LANDING_PIECE = 'O',
                           EMPTY = ' ', INVALID = '0'};
enum Move : char {ADVANCE, CAPTURE, NO_MOVE};

enum Players: char {P1, P2};

#endif //__SENET_CONSTANTS_H__