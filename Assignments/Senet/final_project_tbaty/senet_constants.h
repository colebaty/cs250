#ifndef __SENET_CONSTANTS_H__
#define __SENET_CONSTANTS_H__

enum PlayerOnePiece : char {ONE = '1', TWO = '2', THREE = '3', FOUR = '4', FIVE = '5'};
enum PlayerTwoPiece : char {A = 'A', B = 'B', C = 'C', D = 'D', E = 'E'};
enum Trap : int {TRAP = 27, LANDING = 15};

const char TRAP_PIECE = 'X';
const char EMPTY = ' ';
const char INVALID = '0';

#endif //__SENET_CONSTANTS_H__