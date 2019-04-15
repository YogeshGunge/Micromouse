# Micromouse

## What is micromouse?
Micromouse is an event where small robot mice solve a 16 × 16 maze.
[Read more about micromouse](https://en.wikipedia.org/wiki/Micromouse)

A micromouse simulation program written in C using 3 algorithms:
1. Backtracking Method : Bellman [Flood-fill](https://en.wikipedia.org/wiki/Flood_fill) algorithm
2. ShortestPath Method : [Dijkstra's](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) algorithm
3. HeuristicsGuided Backtracking Method : [Greedy Search](https://en.wikipedia.org/wiki/Greedy_algorithm) algorithm
4. HeuristicsGuided Shortest Path Method : [A* Search](https://en.wikipedia.org/wiki/A*_search_algorithm) algorithm

Backtracking Method aims to traverse the whole maze and get idea of complete maze, when the robot mouse has no idea of where the walls are exactly. It is a [breadth-first search algorithm](https://en.wikipedia.org/wiki/Breadth-first_search).

ShortestPath Method aims to find shortest path between any two given points in the maze, when the robot mouse knows where are walls and where there is a way. It is a [depth-first search algorithm](https://en.wikipedia.org/wiki/Depth-first_search).

HeuristicsGuided Method aims to find shortest path between any two given points in the maze, when the robot mouse does not know where are walls and where there is a way. It is a [informed search algorithm](https://en.wikipedia.org/wiki/Search_algorithm#Informed_search) and it takes a greedy approach by trying to get to the target by going to the closest block that takes to the target. In this greedy search approach, we expand the node closest to the target node. The “closeness” is estimated by a heuristic h(x).
Heuristic: A heuristic h is defined as h(x) = Estimate of distance of node x from the goal node.
Lower the value of h(x), closer is the node from the goal.
Strategy: Expand the node closest to the goal state, i.e. expand the node with lower h value.
Mathematically,
h(x) = f(x), f(x) - manhattan distance of block from target location

HeuristicsGuided Shortest Path Method is also a [informed search algorithm](https://en.wikipedia.org/wiki/Search_algorithm#Informed_search), but a [best-first search algorithm](https://en.wikipedia.org/wiki/Best-first_search). It is formulated in terms of weighted graphs: starting from a specific starting node of a graph, it aims to find a path to the given goal node having the smallest cost (least distance travelled, shortest time, etc.). It does this by maintaining a tree of paths originating at the start node and extending those paths one edge at a time until its termination criterion is satisfied.
For example, consider solution given by greedy and A* for below problem:
```C
+-+-+-+-+
|   |   |
+ + + + +
|     | |
+ +-+ + +
|     | |
+-+-+-+ +
|       |
+-+-+-+-+

Greedy solution:
+-+-+-+-+
|* *|* *|
+ + + + +
|* * *|*|
+ +-+ + +
|* * *|*|
+-+-+-+ +
|       |
+-+-+-+-+

Solution is:
Start -> Right -> Down -> Right -> Up -> Right -> Down -> Down -> Down -> Target

+-+-+-+-+
|* *|* *|
+ + + + +
|  * *|*|
+ +-+ + +
|* * *|*|
+-+-+-+ +
|      *|
+-+-+-+-+

Solution is:
Start -> Right -> Down -> Right -> Up -> Right -> Down -> Down -> Down -> Target

Here, A* does not visit block at second row and first column, whereas greedy visits that block.
```

Source: ttps://en.wikipedia.org

## Getting started
1. Do the git clone on this repository.
2. Run `make` to build an executable **simulate** file and its associated compiled files.
3. Run `./simulate` to accept maze input from user and print maze as mouse traverses the maze.

## Removing compiled files
Run `make clean` to remove all compiled .o files

Run `make distclean` to remove all compiled .o files including the executable **hello** file.

## How to draw maze (input to program)
Press enter to draw all and press space to leave it empty

## How to change size of maze
change MAX macro constant in code file

## Sample output using Backtracking
```C
./simulate

+-+-+-+-+
|       |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Enter row and colomn of starting position:0 0


Maze Traced:-
+-+-+-+-+
|*      |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 0 1

Maze Traced:-
+-+-+-+-+
|* *    |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 0 2

Maze Traced:-
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 0 3

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 1 3

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |  *|
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 1 2

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |* *|
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 1 3

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |* *|
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 2 3

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   | |
+-+-+-+-+
Current Mouse Position: 3 3

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 0 2

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 0 0

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 1 0

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|*  |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 1 1

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 2 1

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|  *  |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 2 2

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|  * *|*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Current Mouse Position: 3 2

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|  * *|*|
+ +-+ + +
| |  *|*|
+-+-+-+-+
Current Mouse Position: 3 1

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|  * *|*|
+ +-+ + +
| |* *|*|
+-+-+-+-+
Current Mouse Position: 2 1

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|  * *|*|
+ +-+ + +
| |* *|*|
+-+-+-+-+
Current Mouse Position: 2 0

Maze Traced:-
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|* * *|*|
+ +-+ + +
| |* *|*|
+-+-+-+-+
Current Mouse Position: 3 0
```
Thus, whole maze is traveresed by backtracking algorithm.

## Sample output using ShortestPath
```C
./simulate

+-+-+-+-+
|       |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Enter row and colomn of starting position:0 0

Enter row and colomn of destination position:3 3


Current Maze: 
+-+-+-+-+
|* *    |
+ +-+ + +
|*  |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|* *|   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|*  |
+-+ +-+ +
|  *  | |
+ +-+ + +
| |   | |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|* * *| |
+ +-+ + +
| |   | |
+-+-+-+-+

Current Maze: 
+-+-+-+-+
|* * * *|
+ +-+ + +
|* *|* *|
+-+ +-+ +
|* * *|*|
+ +-+ + +
|*|  *| |
+-+-+-+-+

Solution is:
Start -> Right -> Right -> Right -> Down -> Down -> Down -> Target
```
Thus, shortest path is found by floodfill algorithm.

## Sample output using Greedy (HeuristicsGuided Backtracking)
```C
./simulate

+-+-+-+-+
|       |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Enter row and colomn of starting position:0 0

Enter row and colomn of destination position:3 3

Distance0 is 13
Distance3 is 13
Direction chosen by mouse 0 is Right
Distance travelled by mouse 0 is 1
Current Maze: 
+-+-+-+-+
|* *    |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance0 is 10
Direction chosen by mouse 0 is Right
Distance travelled by mouse 0 is 2
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance0 is 9
Distance3 is 5
Direction chosen by mouse 0 is Down
Distance travelled by mouse 0 is 3
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |*  |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance0 is 4
Direction chosen by mouse 0 is Right
Distance travelled by mouse 0 is 4
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |* *|
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance1 is 9
Distance3 is 1
Direction chosen by mouse 0 is Down
Distance travelled by mouse 0 is 5
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   | |
+-+-+-+-+
Distance3 is 0
Direction chosen by mouse 0 is Down
Distance travelled by mouse 0 is 6

Solution is:
Start -> Right -> Right -> Down -> Right -> Down -> Down -> Target
```

## Sample output using A* (HeuristicsGuided ShortestPath)
```C
./simulate

+-+-+-+-+
|       |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Enter row and colomn of starting position:0 0

Enter row and colomn of destination position:3 3


Number of links of mouse 0 at (0, 0) is 2
Direction chosen by mouse 0 at (0, 0) is Right, bcoz distance = 13
Closest mouse 0 at (0, 0), at distance from target = 13, nlinks is 2, direction is 0
Added 1 more mouse at (0, 0), top is 1
Direction taken by mouse 0 at (0, 0) is Right and moved to (0, 1).
Distance travelled by mouse 0 at (0, 1) is 1
Current Maze: 
+-+-+-+-+
|* *    |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance of mouse 0 at (0, 1) from (3, 3) is : 13

Total number of mouse is : 2


Number of links of mouse 0 at (0, 1) is 1
Direction chosen by mouse 0 at (0, 1) is Right, bcoz distance = 10

Number of links of mouse 1 at (0, 0) is 1
Direction chosen by mouse 1 at (0, 0) is Down, bcoz distance = 13
Closest mouse 0 at (0, 1), at distance from target = 10, nlinks is 1, direction is 0
Direction taken by mouse 0 at (0, 1) is Right and moved to (0, 2).
Distance travelled by mouse 0 at (0, 2) is 2
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |   |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance of mouse 0 at (0, 2) from (3, 3) is : 10

Total number of mouse is : 2


Number of links of mouse 0 at (0, 2) is 2
Direction chosen by mouse 0 at (0, 2) is Down, bcoz distance = 5

Number of links of mouse 1 at (0, 0) is 1
Direction chosen by mouse 1 at (0, 0) is Down, bcoz distance = 13
Closest mouse 0 at (0, 2), at distance from target = 5, nlinks is 2, direction is 3
Added 1 more mouse at (0, 2), top is 2
Direction taken by mouse 0 at (0, 2) is Down and moved to (1, 2).
Distance travelled by mouse 0 at (1, 2) is 3
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |*  |
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance of mouse 0 at (1, 2) from (3, 3) is : 5

Total number of mouse is : 3


Number of links of mouse 0 at (1, 2) is 1
Direction chosen by mouse 0 at (1, 2) is Right, bcoz distance = 4

Number of links of mouse 1 at (0, 0) is 1
Direction chosen by mouse 1 at (0, 0) is Down, bcoz distance = 13

Number of links of mouse 2 at (0, 2) is 1
Direction chosen by mouse 2 at (0, 2) is Right, bcoz distance = 9
Closest mouse 0 at (1, 2), at distance from target = 4, nlinks is 1, direction is 0
Direction taken by mouse 0 at (1, 2) is Right and moved to (1, 3).
Distance travelled by mouse 0 at (1, 3) is 4
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |* *|
+-+ +-+ +
|     | |
+ +-+ + +
| |   | |
+-+-+-+-+
Distance of mouse 0 at (1, 3) from (3, 3) is : 4

Total number of mouse is : 3


Number of links of mouse 0 at (1, 3) is 2
Direction chosen by mouse 0 at (1, 3) is Down, bcoz distance = 1

Number of links of mouse 1 at (0, 0) is 1
Direction chosen by mouse 1 at (0, 0) is Down, bcoz distance = 13

Number of links of mouse 2 at (0, 2) is 1
Direction chosen by mouse 2 at (0, 2) is Right, bcoz distance = 9
Closest mouse 0 at (1, 3), at distance from target = 1, nlinks is 2, direction is 3
Added 1 more mouse at (1, 3), top is 3
Direction taken by mouse 0 at (1, 3) is Down and moved to (2, 3).
Distance travelled by mouse 0 at (2, 3) is 5
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   | |
+-+-+-+-+
Distance of mouse 0 at (2, 3) from (3, 3) is : 1

Total number of mouse is : 4


Number of links of mouse 0 at (2, 3) is 1
Direction chosen by mouse 0 at (2, 3) is Down, bcoz distance = 0

Number of links of mouse 1 at (0, 0) is 1
Direction chosen by mouse 1 at (0, 0) is Down, bcoz distance = 13

Number of links of mouse 2 at (0, 2) is 1
Direction chosen by mouse 2 at (0, 2) is Right, bcoz distance = 9

Number of links of mouse 3 at (1, 3) is 1
Direction chosen by mouse 3 at (1, 3) is Up, bcoz distance = 9
Closest mouse 0 at (2, 3), at distance from target = 0, nlinks is 1, direction is 3
Direction taken by mouse 0 at (2, 3) is Down and moved to (3, 3).
Distance travelled by mouse 0 at (3, 3) is 6
Current Maze: 
+-+-+-+-+
|* * *  |
+ +-+ + +
|   |* *|
+-+ +-+ +
|     |*|
+ +-+ + +
| |   |*|
+-+-+-+-+
Distance of mouse 0 at (3, 3) from (3, 3) is : 0

Total number of mouse is : 4


Solution is:
Start -> Right -> Right -> Down -> Right -> Down -> Down -> Target
```
Thus, shortest path is found by heuristic guided search algorithms.
