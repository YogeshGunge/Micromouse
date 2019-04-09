# Micromouse

## What is micromouse?
Micromouse is an event where small robot mice solve a 16 × 16 maze.
[Read more about micromouse](https://en.wikipedia.org/wiki/Micromouse)

A micromouse simulation program written in C using 3 algorithms:
1. Backtracking Method : Bellman [Flood-fill](https://en.wikipedia.org/wiki/Flood_fill) algorithm
2. ShortestPath Method : [Dijkstra's](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) algorithm
3. HeuristicGuided Method : [A* Search](https://en.wikipedia.org/wiki/A*_search_algorithm) algorithm

Backtracking Method aims to traverse the whole maze and get idea of complete maze.
ShortestPath Method aims to find shortest path between any two given points in the maze.

## Getting started
1. Do the git clone on this repository.
2. Run `make` to build an executable **simulate** file and its associated compiled files.
3. Run `./simulate` to accept maze input from user and print maze as mouse traverses the maze.

## Removing compiled files
Run `make clean` to remove all compiled .o files

Run `make distclean` to remove all compiled .o files including the executable **hello** file.

# How to draw maze
Press enter to draw all and press space to leave it empty

## Sample output using Backtracking
./simulate

+-+-+-+-+
|   |   |
+ +-+ + +
| |   | |
+ + +-+ +
| | |   |
+ + + + +
|   |   |
+-+-+-+-+
Enter row and colomn of starting position:0 0


Maze Traced:-
+-+-+-+-+
|*  |   |
+ +-+ + +
| |   | |
+ + +-+ +
| | |   |
+ + + + +
|   |   |
+-+-+-+-+
Current Mouse Position: 0 1

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
| |   | |
+ + +-+ +
| | |   |
+ + + + +
|   |   |
+-+-+-+-+
Current Mouse Position: 0 0

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
| |   | |
+ + +-+ +
| | |   |
+ + + + +
|   |   |
+-+-+-+-+
Current Mouse Position: 1 0

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
| | |   |
+ + + + +
|   |   |
+-+-+-+-+
Current Mouse Position: 2 0

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|*| |   |
+ + + + +
|   |   |
+-+-+-+-+
Current Mouse Position: 3 0

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|*| |   |
+ + + + +
|*  |   |
+-+-+-+-+
Current Mouse Position: 3 1

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|*| |   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 2 1

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|*|*|   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 1 1

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|*  | |
+ + +-+ +
|*|*|   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 1 2

Maze Traced:-
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|* *| |
+ + +-+ +
|*|*|   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 0 2

Maze Traced:-
+-+-+-+-+
|* *|*  |
+ +-+ + +
|*|* *| |
+ + +-+ +
|*|*|   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 0 3

Maze Traced:-
+-+-+-+-+
|* *|* *|
+ +-+ + +
|*|* *| |
+ + +-+ +
|*|*|   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 1 3

Maze Traced:-
+-+-+-+-+
|* *|* *|
+ +-+ + +
|*|* *|*|
+ + +-+ +
|*|*|   |
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 2 3

Maze Traced:-
+-+-+-+-+
|* *|* *|
+ +-+ + +
|*|* *|*|
+ + +-+ +
|*|*|  *|
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 2 2

Maze Traced:-
+-+-+-+-+
|* *|* *|
+ +-+ + +
|*|* *|*|
+ + +-+ +
|*|*|* *|
+ + + + +
|* *|   |
+-+-+-+-+
Current Mouse Position: 3 2

Maze Traced:-
+-+-+-+-+
|* *|* *|
+ +-+ + +
|*|* *|*|
+ + +-+ +
|*|*|* *|
+ + + + +
|* *|*  |
+-+-+-+-+
Current Mouse Position: 3 3

Maze Traced:-
+-+-+-+-+
|* *|* *|
+ +-+ + +
|*|* *|*|
+ + +-+ +
|*|*|* *|
+ + + + +
|* *|* *|
+-+-+-+-+
Current Mouse Position: 2 3

# Sample output using ShortestPath
./simulate

+-+-+-+-+
|   |   |
+ +-+ + +
| |   | |
+ + +-+ +
|       |
+ +-+-+ +
|       |
+-+-+-+-+
Enter row and colomn of starting position:0 0

Enter row and colomn of destination position:3 3


Current Maze: 
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|       |
+ +-+-+ +
|       |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|*      |
+ +-+-+ +
|       |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|   | |
+ + +-+ +
|* *    |
+ +-+-+ +
|*      |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|*  | |
+ + +-+ +
|* * *  |
+ +-+-+ +
|* *    |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* *|   |
+ +-+ + +
|*|* *| |
+ + +-+ +
|* * * *|
+ +-+-+ +
|* * *  |
+-+-+-+-+

Solution is:
Start -> Down -> Down -> Down -> Right -> Right -> Right -> Target
