# Labyrinth Solver

# Description of the algorithms and purpose of the exercise:

A C ++ program that performs two main purposes:
1. Exit a given maze.
2. Creation of a random maze.

You will be asked to write a function that exits a maze using the queue and a function that creates a maze using the stack.
A maze is simply a two-dimensional array of walls and free spaces, with or without any given free space a wall. We represent a free space by space and a wall by, * where the whole maze is surrounded by walls, except for the corner of the entrance and the corner of the exit.

The beginning of the maze will be in the upper left corner and the exit of the maze will be in the lower right corner.

The maze has of course height and width, (h, w) when the upper left square is in place (0,0) and the right lower square is in place (h-1, w-1).

In a proper maze the bottom row, top row, left column and right column will always have walls represented by asterisks, except for entering and exiting the maze.

It is said that two squares in the maze are "accessible" if they are neighbors in the maze and are in the same row or column, and there is no wall between them. Note that it is forbidden to walk diagonally, but only in four directions (left, right, up, down,) of course only if there is no wall.

# Maze Solution by Queue:

Solving a maze means looking for the exit point when we start at the entry point. To ensure that we find the exit (if there is a route to it,) we must make sure that we go through all the possible squares in the maze. The turn will allow us to remember where we have already visited and decide which next square to visit.
We will use is:
 
1. We will initialize the queue in a box. (1,0)
2. As long as the queue is not empty:
• We will lower the location of the slot we marked in front of the queue that we visited.
• If the current slot we downloaded is the end point then we will exit the loop because we left the maze.
• Other: We will add to the queue all the squares that can be reached from the current square and which have not yet
We visited them and will continue in the main loop.
Note that the queue contains spaces of empty squares that contain spaces, and every time we remove a square from the queue we check the neighbors around that can be reached and then add them to the queue (if we have not been there yet) to check them later.

Because the queue operates in the form of FIFO then the form of search will look like water spilling from the starting point (possibly through the whole maze), until you reach the end point.

To allow a uniform examination of your exercises be sure to visit neighbors in the following order: right, down,
Left, up.

Your output in the case of a maze solution will not only be the path leading to the exit, but the entire maze where all the squares you visited until you found the exit are marked (the squares you visited are marked with a $ sign). For example in the maze in the example the algorithm will visit all the slots before reaching the exit, but this does not have to be the case and it is quite possible that the algorithm will stop before visiting all the slots (as soon as it reaches the exit). The squares in which $, however, as mentioned, you will mark in your solution the and not in - marked in gray in the example of the algorithm visited by the squares in which you visited $.

Maze creation:

Creating a maze is very similar to solving a maze, but this time the goal is to visit all the empty spaces and remove walls during the visit so that a path is created between any two empty squares by a series of accessible squares. This of course will also ensure there will be a route from the entrance to the exit of the maze. Please note, you must not be left at the end of a series of empty squares that cannot be reached in any way (i.e. a series of empty squares completely surrounded by walls).
Here is the maze creation algorithm:

1) We will start with a maze where all the walls exist, between any two adjacent squares, and of course the walls around the maze except the entrance (1,0) and the exit (h-2, w-1).
2) We will initialize the cartridge with the box (1,1).
3) As long as the cartridge is not empty:
3.1)
• We will remove from the top of the stack the location of the slot we marked that we visited.
• If the current box we downloaded has neighbors we have not yet visited then:
A. A random neighbor of the slot we have not yet visited was chosen.
B. We will lower the wall between the selected neighbor and the current slot.
C. We will return the current box to the stack.
D. We also put the random neighbor selected in the stack.
• We will continue in the main loop.

In fact, this algorithm will visit a maze like a snake crawling until it reaches a dead end (which is a slot without neighbors we have not yet visited), and then the snake goes back until it finds a slot that still has neighbors it has not visited and continues forward again.

Try running the algorithm on the next initial maze that contains all the initial walls to understand how the algorithm works.
