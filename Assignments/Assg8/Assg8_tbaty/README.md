# Assignment 8 Notes

## Game Description

A player has a 10x10 board.  The player places 4 O-Pieces and 8 X-Pieces on the board; additionally two G-pieces are placed on the board adjacent to each other (pieces are set IAW assignment instructions). Using as few moves as possible, the player moves all O-Pieces off the board by reaching the G-Pieces according to the following rules:

- No two pieces may share a square
- G-Pieces do not move once set
- O-Pieces and X-pieces may only move vertically or horizontally
- O-Pieces move as many squares as possible in the desired direction until meeting an obstacle (X-Piece), the edge of the board, or a G-Piece
- X-Pieces move one square in the desired direction provided the target square is not occupied

After a valid turn is played, the player's total number of turns is incremented.  Invalid selections made during a turn to not update the player's total number of turns.

Once an O-piece reaches a G-piece, it is removed from the board and the player's piece total is decremented.

### Winning the game

The game is won when the Player has successfully moved all O-Pieces off the board by reaching G-Pieces.

## ADTs

### Player

```cpp
private:
    int _piecesOnBoard;
    int _numTurns;
    Board* _board;//interact with board through this reference

public:
    Player(Board* board);
    ~Player();

    bool isValidSelection(int row, int col);
    bool hasPieces();
    int getNumRemainingPieces() { return _piecesOnBoard; };
```

### Board
```cpp
enum Direction : char {UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'};
enum Piece : char { PLAYER = 'O', OBSTACLE = 'X', EMPTY = ' ', GOAL = 'G'};

private:
    char _board[10][10];//row, column

public:
    Board();

    void initialize();
    void displayBoard(std::ostream& out=cout);
    char getSquare(int row, int col);
    void setSquare(char piece, int row, int col);
    bool isValidMove(char piece, int row, int col, char dir);
    void movePiece(char piece, int row, int col, char dir);

```

## Valid moves

Each of the following moves is considered a `turn` and increments the Player's
 `_numTurns`.  No piece may move diagonally.

### Player - O
O-Pieces may move horizontally or vertically until an obstacle or the edge of the board is encountered.  Obstacles are X-pieces and other O-pieces. O-pieces may not move diagonally.

### Player - X
X-Pieces may move one square horizontally or vertically, provided the target is on the board and unoccupied.

## Algorithm

```cpp
//play game until all pieces have been moved off board
    //setup
        //declare board, player
        //initialize player
            //set _piecesOnBoard = 4;
            //set _numMoves = 0;
        //initialize board
    //gameplay
        //while not done (player.hasPieces())
            //while piece selection invalid - function
                //player selects a piece
            //while desired move is illegal - function recursive
                //prompt for desired direction
            //if O-piece
                //move piece to target location
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