# Assignment 8 Notes

## ADTs

### Player

```cpp
private:
    int _piecesOnBoard;
    int _numTurns;
    Board* _board;//interact with board through this reference

public:
    Player(Board* board);

    bool isValidSelection(int row, int col);
    bool hasPieces();
    int getNumRemainingPieces() { return _piecesOnBoard; };
```

### Board
```cpp
enum Direction : char {UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'};
enum Piece : char { PLAYER = 'O', OBSTACLE = 'X', EMPTY = ' '};

private:
    char _board[10][10];//row, column

public:
    Board();

    void initialize();
    void displayBoard(std::ostream& out=cout);
    char getSquare(int row, int col);
    void setSquare(char piece, int row, int col);
    bool isValidMove(char piece, int row, int col, char dir)
    void movePiece(char piece, int row, int col, char dir);

```

## Valid moves

Each of the following moves is considered a `turn` and increments the Player's
 `_numTurns`.

### Player - O
O-Pieces may move horizontally or vertically until an obstacle or the edge of the board is encountered.  Obstacles are X-pieces and other O-pieces. O-pieces may not move diagonally.

### Player - X
X-Pieces may move one square in any direction, provided the target is on the board and unoccupied.

## Algorithm

```cpp
//play game until all pieces have been moved off board
    //setup
        //declare board, player
        //initialize player
        //initialize board
    //gameplay
        //while not done (player.hasPieces())
            //while piece selection invalid - function
                //player selects a piece
            //while desired move is illegal - function
                //prompt for desired direction
            //if O-piece
                //move piece until obstacle or goal is encountered - recursive
                //if goal
                    //move piece off board
                    //decrement player's pieces
                //else
                    //leave piece next to obstacle/board edge
            //else (X-piece)
                //move piece one square in desired direction
            //increment player's turn count
            //display - member functions
                //board, 
                //number of turns played, 
                //player pieces remaining - member functions
    //wrap-up
        cout << "puzzle completed in " << player.getNumMoves() << " moves" << endl;
```