
# MAZE STRUCTURES!

<h5>Project	Summary</h5>

This project rendomly generates a maze that can be seen in text in the standard output. It first builds a 2d array grid of custom node structures. It then uses a traversal algortithm to put all nodes into a path. We can then solve this maze by saving the forks as a binary tree! (Note-- 04/27 the tree is still in progress!)

<h5>How	to	Run</h5>

To run, be sure that the Maze.h header and Maze.cpp library live in the same folder as the driver main.cpp file. To build a maze, follow the prompts by typing an integer value between 3 and 10 for the maze dimensions. Further functionality is displayed in a menu and to select any of these options, just enter the number in the standard output.

======Main Menu======
<h3>1 Make a new maze</h3>

<pre>|========================|
|           |            |
|            ======      |
-> S |                   |
|==================      |
|                        |
|      ==================|
|                    **  |
|========================|</pre>

Ready to solve?

<h3>2 Solve the maze</h3>

4->0->1->5->6->7->11->10->9->8->12->13->14->15
Is the whole path

<h3>3 Print the maze </h3>


<pre>|========================|
|           |            |
|            ======      |
-> S |                   |
|==================      |
|                        |
|      ==================|
|                    **  |
|========================|</pre>

<h3>4. Print the maze with indices</h3>



<pre>|========================|
|    0     1|    2     3 |
|            ======      |
-> S |    5     6     7  |
|==================      |
|    8     9    10    11 |
|      ==================|
|   12    13    14   **  |
|========================|</pre>

<h3>5. Print the forks</h3>


7
Are the forks 

<h3>6. Print the dead ends</h3>


4
2
15 
Are the dead ends

<h3>7. Count the forks</h3>


1 fork

<h3>0. Quit</h3>


<h5>Dependencies
Additional libraries include:</h5>

* vector
* iostream
* stack
* cmath
* iomanip
* limits
* cstdlib

Which should all be included installed already with c++...so no installs necessary.

<h5>System	Requirements</h5>

This project was build on Xcode for Mac, and runs on the ubuntu. There are no other known system requirements.

<h5>Group	Members</h5>

Aliisa Roe is the author, with direction from Rhonda Hoenigman's Visualizing Data Structures, and the first couple minutes of this video https://www.youtube.com/watch?v=elMXlO28Q1U. 

<h5>Contributors</h5>
TBD

<h5>Open	issues/bugs</h5>

* Assumed bug that there is a memory leak, from not explicitly deleting denamically allocated memory of the nodes in the 2d array grid. 
* There are many times the maze has no forks, giving one path which may give errors. 
* More public functions should be added. (I probably could move some of my private functions over, but it's hard to justify why they would need to be public...) Forgive me! 
* The tree of forks sets up properly, but need to add the dead end leaves to the tree as well to provides traversal functionality.


GRACIAS TODOS
