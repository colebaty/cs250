# Determine if a ship is sunk

This test case was generated during automated testing, and presents an 
interesting case for detecting who has won.

```
======= run 2 ========
WELCOME TO MODIFIED BATTLESHIP

<snip>

debug: computer attempting to place front piece at (2, 4)
debug: front of ship placed at (2, 4)
debug: direction: LEFT
debug: computer attempting to place back piece at (1, 4)
debug: back of ship placed at (1, 4)
debug: computer attempting to place front piece at (0, 4)
debug: front of ship placed at (0, 4)
debug: direction: UP
debug: computer attempting to place back piece at (0, 5)
debug: back of ship placed at (0, 5)

<snip>

debug: computer player's board

   ___ ___ ___ ___ ___ ___ 
  |   |   |   |   |   |   |
5 | O |   |   |   |   |   |
  |___|___|___|___|___|___|
  |   |   |   |   |   |   |
4 | O | O | O |   |   |   |
  |___|___|___|___|___|___|
  |   |   |   |   |   |   |
3 |   |   |   |   |   |   |
  |___|___|___|___|___|___|
  |   |   |   |   |   |   |
2 |   |   |   |   |   |   |
  |___|___|___|___|___|___|
  |   |   |   |   |   |   |
1 |   |   |   |   |   |   |
  |___|___|___|___|___|___|
  |   |   |   |   |   |   |
0 |   |   |   |   |   |   |
  |___|___|___|___|___|___|
    0   1   2   3   4   5   

Computer's ships have been randomly placed.
===== run 2 complete =====
```

Note that the ships were placed in this order

* Ship 1 at (2, 4) (1, 4)
* Ship 2 at (0, 4) (0, 5)

The game is won by the first player to sink both opponent's ships.