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
This program complies using g++:
g++ -std=c++17 monopoly_board.cpp -o monopoly_board

#Run
Run the program with:
./monopoly_board

The program will: 
- Build a monopoly board
- Display all spaces
- Simulate 10 player turns
- Show player positions and nearby spaces after each dice roll

#Data Structures

1. MonopolySpace Class
The MonopolySpace class represents one space on the board.
The space stores:
- propertyName – the name of the space
- propertyColor – the color group of the property
- value – the purchase price
- rent – the rent amount
Example of a space: Boardwalk : Blue : $400 : Rent $50
The class also has a constructor to set the space's information and print() function to display space.

2. Node Template Class
The Node<T> class represents a node in the circular linked list.
Each node contains:
- data → the MonopolySpace object
- nextNode → pointer to the next node
The node can store different data types because it is a template class.

3. CircularLinkedList Template Class






