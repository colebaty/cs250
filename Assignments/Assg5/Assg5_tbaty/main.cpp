#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <time.h>//to seed srand

using namespace std;

enum direction:int {UP, DOWN, LEFT, RIGHT};

// check if a certain position on the board is occupied by a human ship. 1 indicates health ship, 2 indicated sunk portion of ship
string checkPos(int x, int y, int human[][6])
{
    string str = "";
    if(human[x][y] == 1)
        str = "O";
    else if(human[x][y] == 2)
        str = "X";
    else
        str = " ";

    return str;
}

//print the human's side of the board. This will show if the ships placed are hit
void printBoard(int human[][6], int computer[][6])
{
    #ifdef DEBUG
    cerr << "\ndebug: human player's board" << endl;
    #endif
    cout << "\n";
    cout << "   ___ ___ ___ ___ ___ ___ " << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "5 | " << checkPos(0, 5, human) << " | " << checkPos(1, 5, human) <<" | " << checkPos(2, 5, human) << " | " << checkPos(3, 5, human) << " | " << checkPos(4, 5, human) << " | " <<  checkPos(5, 5, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "4 | " <<  checkPos(0, 4, human) << " | " << checkPos(1, 4, human) << " | " << checkPos(2, 4, human) << " | " << checkPos(3, 4, human) << " | " << checkPos(4, 4, human) << " | " << checkPos(5, 4, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "3 | " << checkPos(0, 3, human) << " | " <<  checkPos(1, 3, human) << " | " << checkPos(2, 3, human) << " | " <<  checkPos(3, 3, human) << " | " << checkPos(4, 3, human) << " | " <<  checkPos(5, 3, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "2 | " <<  checkPos(0, 2, human) << " | " << checkPos(1, 2, human) << " | " <<  checkPos(2, 2, human) << " | " << checkPos(3, 2, human) << " | " <<  checkPos(4, 2, human) << " | " << checkPos(5, 2, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "1 | " << checkPos(0, 1, human) << " | " <<  checkPos(1, 1, human) << " | " << checkPos(2, 1, human) << " | " << checkPos(3, 1, human) << " | " << checkPos(4, 1, human) << " | " <<  checkPos(5, 1, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "0 | " << checkPos(0, 0, human) << " | " << checkPos(1, 0, human) << " | " <<  checkPos(2, 0, human) << " | " << checkPos(3, 0, human) << " | " <<  checkPos(4, 0, human) << " | " << checkPos(5, 0, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "    0   1   2   3   4   5   \n" << endl;

    #ifdef DEBUG
    cout << "debug: computer player's board" << endl;
    cout << "\n";
    cout << "   ___ ___ ___ ___ ___ ___ " << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "5 | " << checkPos(0, 5, computer) << " | " << checkPos(1, 5, computer) <<" | " << checkPos(2, 5, computer) << " | " << checkPos(3, 5, computer) << " | " << checkPos(4, 5, computer) << " | " <<  checkPos(5, 5, computer) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "4 | " <<  checkPos(0, 4, computer) << " | " << checkPos(1, 4, computer) << " | " << checkPos(2, 4, computer) << " | " << checkPos(3, 4, computer) << " | " << checkPos(4, 4, computer) << " | " << checkPos(5, 4, computer) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "3 | " << checkPos(0, 3, computer) << " | " <<  checkPos(1, 3, computer) << " | " << checkPos(2, 3, computer) << " | " <<  checkPos(3, 3, computer) << " | " << checkPos(4, 3, computer) << " | " <<  checkPos(5, 3, computer) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "2 | " <<  checkPos(0, 2, computer) << " | " << checkPos(1, 2, computer) << " | " <<  checkPos(2, 2, computer) << " | " << checkPos(3, 2, computer) << " | " <<  checkPos(4, 2, computer) << " | " << checkPos(5, 2, computer) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "1 | " << checkPos(0, 1, computer) << " | " <<  checkPos(1, 1, computer) << " | " << checkPos(2, 1, computer) << " | " << checkPos(3, 1, computer) << " | " << checkPos(4, 1, computer) << " | " <<  checkPos(5, 1, computer) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "0 | " << checkPos(0, 0, computer) << " | " << checkPos(1, 0, computer) << " | " <<  checkPos(2, 0, computer) << " | " << checkPos(3, 0, computer) << " | " <<  checkPos(4, 0, computer) << " | " << checkPos(5, 0, computer) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "    0   1   2   3   4   5   \n" << endl;
    #endif
}

void initializePieces(int human[][6], int computer[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            human[i][j] = 0;
            computer[i][j] = 0;
        }
}

//for generating random initial placement of computer's pieces
//rand() % n produces random numbers between [0, n-1]
int GetRandomBetween(int ceiling)
{
    return rand() % (ceiling + 1);//includes 0
}

/*
    function to check whether a space neighboring (x, y) is legally occupied. 
    assumes x, y have already been validated as existing on board.  
    returns true if:
        - any legal neighboring square is occupied (for all squares in range):
            - (x+1, y), (x-1, y) - horizontal neighbors
            - (x, y+1), (x, y-1) - vertical neighbors
    
    returns false otherwise

    @param x - the x coordinate 
    @param y - the y coordinate 
    @param board - the player's board
*/
bool checkForNeighbor(int x, int y, int board[][6])
{
    if (checkPos(x+1, y, board) != " ") 
        return true;//right
    if (checkPos(x-1, y, board) != " ") 
        return true;//left
    if (checkPos(x, y+1, board) != " ") 
        return true;//up
    if (checkPos(x, y-1, board) != " ")
        return true;//down
    
    return false;
}

/*
    places a ship piece on the player's board
    ensures input validation takes place
        - accepts only integers within the range of the board
        - ensures no piece is placed in an already occupied space
        - ensures the "back" piece of the ship is placed in a valid space
          neighboring the first placed piece
    
    this function may seem long but I can't resist reusability
*/
void placeShip(int board[][6], bool isHuman)
{
    //initialize seed
    srand(time(NULL));

    int x, y;
    bool done = false;
    bool front = true;
    while (!done)
    {
        if (isHuman)
        {
            cout << "Enter the coordinates of the ";
            if (front)
                cout << "front";
            else
                cout << "back";
                
            cout << " of the ship (ex: 1 2)" << endl;

            cin.sync();
            cin >> x >> y;
            cout << endl;
            
            #ifdef DEBUG
            cerr << "debug: Player entered (" << x << ", " << y << ")" << endl;
            #endif

            //invalid input
            if (!cin)
            {
                cerr << "Invalid input - please try again" << endl << endl;
                cin.clear();
                continue;
            }
            //invalid placement - not on board
            if (x < 0 || x > 5 || y < 0 || y > 5) 
            {
                cerr << "Invalid placement - not on board" << endl << endl;
                continue;
            }
            //invalid placement - space alrady occupied
            if (checkPos(x, y, board) != " ")
            {
                cerr << "Invalid placement - space already occupied" << endl << endl;
                continue;
            }
            //check for valid placement of second piece
            if (!front)
            {
                //here (x, y) is for the "back" piece.  if the neighbor is
                //occupied, then this is a valid choice selection
                if (!checkForNeighbor(x, y, board))
                {
                    cerr << "Invalid placement - not a valid neighboring square" << endl << endl;
                    continue;
                }
            }
        }
        else //computer places ship
        {
            if (front)
            {
                //get front
                do
                {
                    //generate random (x,y), 0 <= x,y <= 5;
                    x = GetRandomBetween(5);
                    y = GetRandomBetween(5);
                } while (checkPos(x, y, board) != " ");

                #ifdef DEBUG
                cerr << "debug: computer attempting to place front piece at ("
                     << x << ", " << y << ")" << endl;
                #endif

            }
            else //back piece
            {
                do
                {
                    //generate second coord
                    //* choose one of the valid neighbors
                    // randomly choose one of the neighbors
                    int direction = GetRandomBetween(RIGHT);//RIGHT == 3
                    
                    #ifdef DEBUG
                    cerr << "debug: direction: ";
                    switch (direction)
                    {
                    case UP:
                        cerr << "UP" << endl;
                        break;
                    
                    case DOWN:
                        cerr << "DOWN" << endl;
                        break;
                    
                    case LEFT:
                        cerr << "LEFT" << endl;
                        break;
                    
                    case RIGHT:
                        cerr << "RIGHT" << endl;
                        break;
                    }
                    #endif

                    int tempY;
                    int tempX;
                    switch (direction)
                    {
                    case UP:
                        tempY = y + 1;
                        if (tempY > 5) continue;//off the board
                        else if (checkPos(x, tempY, board) == " ") y = tempY;

                        break;
                        
                    case DOWN:
                        tempY = y - 1;
                        if (tempY < 0) continue;//off the board
                        else if (checkPos(x, tempY, board) == " ") y = tempY;
                        
                        break;

                    case LEFT:
                        tempX = x - 1;
                        if (tempX < 0) continue;//off the board
                        else if (checkPos(tempX, y, board) == " ") x = tempX;

                        break;

                    case RIGHT:
                        tempX = x + 1;
                        if (tempX > 5) continue;//off the board
                        else if (checkPos(tempX, y, board) == " ") x = tempX;

                        break;
                    }
                    #ifdef DEBUG
                    cerr << "debug: computer attempting to place back piece at (" << x << ", " << y << ")" << endl;
                    #endif
                } while (checkPos(x, y, board) != " ");
            }
        }

        //place the piece on the board
        board[x][y] = 1;

        //update bool switches, Ship
        if (front)
        {
            #ifdef DEBUG
            cerr << "debug: front";
            #endif
            front = false;//go round again for the back piece
        }
        else 
        {
            #ifdef DEBUG
            cerr << "debug: back";
            #endif
            done = true;//we're finished
        }
        #ifdef DEBUG
        cerr << " of ship placed at (" << x << ", " << y << ")" << endl;
        #endif
    }

}

/*
    checks whether the given coordinate is a hit.
    returns true if hit detected; returns false otherwise.
    if hit detected, updates given hitCount.
*/
bool checkHit(int x, int y, int board[][6], int& hitCount)
{
    string result = checkPos(x, y, board);
    if (result == " ")
    {
        //**** else, announce miss
        cout << "Miss..." << endl << endl;
        return false;
    }
    else if (result == "X")
    {
        //**** else, announce miss
        cout << "Miss - (" << x << ", " << y << ") has already been hit" << endl << endl;
        return false;
    }
    else if (result == "O")
    {
        //**** if hit, announce hit
        cout << "HIT!" << endl << endl;
        board[x][y] = 2;//record hit
        hitCount++;
        return true;
    }

    return false;
}

/*
    starting with human player, alternates turns until a player has sunk
    both opponent's ships
*/
void findWinner(int human[][6], int computer[][6])
{
    bool winnerFound = false;
    int hitCountH, hitCountC;//first player to 4 hits has won
    int x, y;
    x = y = hitCountC = hitCountH = 0;

    //* determine a winner (while there's no winner)
    bool isHuman = true;//human player starts
    while (!winnerFound)
    {
        //** take turns guessing other player's positions
        //*** human player guesses
        if (isHuman)
        {
            cout << "Player, enter the position you would like to attack "
                 << "(ex: 1 1)" << endl;

            cin.sync();
            cin >> x >> y;
            cout << endl;
            
            //invalid input
            if (!cin)
            {
                cerr << "Invalid input - please try again" << endl << endl;
                cin.clear();
                continue;
            }
            //invalid placement - not on board
            if (x < 0 || x > 5 || y < 0 || y > 5) 
            {
                cerr << "Invalid placement - not on board" << endl 
                     << "Please try again" << endl << endl;
                continue;
            }
            #ifdef DEBUG
            cerr << "debug: Player attacking (" << x << ", " << y << ")" << endl;
            #endif

            //check if hit strikes OPPONENT's ships
            checkHit(x, y, computer, hitCountH);

            //***** if human won, announce as winner, end game
            if (hitCountH == 4)
            {
                cout << "Player wins!" << endl;
                winnerFound = true;
            }
        }
        else //***** else continue
        {
            //generate random guess
            x = GetRandomBetween(5);
            y = GetRandomBetween(5);

            cout << "Computer has attacked position (" << x << ", " << y << ")" << endl;

            if (checkHit(x, y, human, hitCountC)) printBoard(human, computer);

            //***** if computer won, announce as winner, end game
            if (hitCountC == 4)
            {
                cout << "Computer wins." << endl;
                winnerFound = true;
            }
        }
        //play nice and take turns
        if (isHuman) isHuman = false;
        else isHuman = true;

        #ifdef DEBUG
        printBoard(human, computer);
        #endif
    }

}

void playGame(int human[][6], int computer[][6])
{
    ///complete this function
    cout << "WELCOME TO MODIFIED BATTLESHIP" << endl << endl << endl;

    // play the game until a player has won
    //* each player sets up their board

    //** human player sets two ships' positions
    //*** human player sets first ship
    cout << "Player, please place your first ship of length 2" << endl;
    placeShip(human, true);

    //*** human player sets second ship
    cout << "Player, please place your second ship of length 2" << endl;
    placeShip(human, true);

    //** computer player sets two ships' positions
    //*** computer player sets first ship
    placeShip(computer, false);

    //*** computer player sets second ship
    placeShip(computer, false);

    printBoard(human, computer);

    cout << "Computer's ships have been randomly placed." << endl;

    //* determine a winner (while there's no winner)
    findWinner(human, computer);
}

int main(int argc, char **argv)
{
    int human[6][6];
    int computer[6][6];
    initializePieces(human, computer);
    playGame(human, computer);
    return 0;
}
