# Roe_CSCI2270_FinalProject

Project	Summary

This project rendomly generates a maze that can be seen in the standard output. It first builds a 2d array grid of custom node structures. It then uses a traversal algortithm using a stack to put all nodes into a path relationship with each other. Forks in the maze are saved to a tree structure, which can later be traversed to show all the various paths possible in the maze. (TODO).

How	to	Run

To run, be sure that the Maze.h header and Main.cpp library live in the same folder as the driver main.cpp file. To build a maze, follow the prompts by typing an integer value between 3 and 10 for the maze dimensions. Further functionality is displayed in a menu. To select any of these options, just type the number before the period and press enter.

======Main Menu======
1. Make a new maze

ex.
==========================
|           |            |
|            ======      |
 -> S |                  |
|==================      |
|                        |
|      ==================|
|                    **  |
|=========================

Ready to solve?


2. Solve the maze

ex.
4->0->1->5->6->7->11->10->9->8->12->13->14->15
Is the whole path
    
3. Print the maze 

ex.
==========================
|           |            |
|            ======      |
 -> S |                  |
|==================      |
|                        |
|      ==================|
|                    **  |
|=========================

4. Print the maze with indexes

ex.
==========================
|    0     1|    2     3 |
|            ======      |
 -> S |    5     6     7 |
|==================      |
|    8     9    10    11 |
|      ==================|
|   12    13    14   **  |
|=========================

5. Print the forks

ex.
7
Are the forks 

6. Print the dead ends

ex.
4
2
15 
Are the dead ends

7. Count the forks

ex.
1 fork

0. Quit


Dependencies
Additional libraries include:

vector
iostream
stack
cmath
iomanip
Which should all be included installed already with c++.

System	Requirements

This project was build on Xcode for Mac, and runs on the ubuntu. There are no other known system requirements.

Group	Members

Aliisa Roe is the author , with direction from Rhonda Hoenigman's Visualizing Data Structures, and the first couple minutes of this video https://www.youtube.com/watch?v=elMXlO28Q1U. 

Contributors
TBD

Open	issues/bugs
List	any	known	bugs	in	the	project,	and	any	open	enhancement	requests.

Assumed bug that there is a memory leak, from not explicitly deleting denamically allocated memory of the nodes in the 2d array grid. 
There are many times the maze has no forks, giving one path which may give errors. 
More public functions should be added. 
The tree of forks sets up properly, but need to add the dead end leaves to the tree as well to provides traversal functionality.


GRACIAS TODOS

