# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

#Overview
This program creates a Monopoly-style game using a circular list in C++. 
The nodes on the list represent the spaces on the Monopoly board.
The last node connects to the first node forming a circle so that the player can move around the board.
This is not a complete monopoly game but this program demonstrates board movement and traveral work.
This program includes:
- Circular Linked List Construction
- Traversal-based movement
- Dice-based player turns
- Player location detection
- And board limits and edge cases

#Board Constraints
The Monopoly Board has a maximum limit of 40 spaces and is set up in the program with this constant:
static const int MAX_SPACES = 40;
The addspace() function checks the limit before adding more nodes, and it will return false if it tries to add more than 40.
This makes it so that circular list never exceeds 40 spaces.

#Build


