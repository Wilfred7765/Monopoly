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
The CircularLinkedList<T> class manages the board and performs all list operations.
Internal Pointers:
- headNode -> first space on the board
- tailNode -> last space (links back to head)
- playerNode -> current player position
- nodeCount -> how many spaces are on the board
- passGoCount -> number of times player passed GO
The program connects the last node back to the first node to have a circular structure:
tailNode->nextNode = headNode;

#Function List and Explanations

addSpace(T value)
This function adds a new space to the board.
Behavior:
- Creates a new node
- Adds node to the end of the list (tail)
- Keeps list circular
- Enforces the 40-space limit
Returns:
true  -> if space is added succesfully
false -> if board is already has 40 spaces

addMany(vector<T> values)
This function adds several spaces to the board at once.
Behavior:
- Calls addSpace() for each value
- Stops adding when the board reaches the capacity
Returns:
The number of spaces added to the board.

movePlayer(int steps)
This function moves the player forward around the board.
Behavior:
- Traverses the circular list node-by-node
- Moves exactly steps nodes forward
- Detects when the player passes the tail node
- Increases passGoCount when the player passes GO
This function uses only pointer traversal, no indexing.

printFromPlayer(int count)
This function shows the spaces starting from the player's current position.
Behavior:
- Prints count consecutive spaces
- Moves forward using pointer traversal
- Stops after the specified number of spaces
Used to display nearby board spaces after a move.

getPassGoCount()
This function returns how many times the player has passed GO.

printBoard()
This function prints the entire board.
Behavior:
- Starts from headNode
- Moves through circular list
- Stops after returning to the starting node
Uses a do–while loop so that every space is printed exactly once.

removeByName(string name)

This function deletes the first space with the matching name.
Behavior:
- Removing the head node
- Removing the tail node
- Removing the only node in the list
- Updates playerNode if needed
Returns:
true  -> if space was deleted
false -> if no matching space exists

findByColor(string color)
This function finds spaces with a specific color group.
Behavior:
- Traverses the circular list once
- Stores matching property names in a vector<string>
Returns:
The vector of matching property names.

countSpaces()
This function counts how many spaces are on the board.
Behavior:
- Traverses the circular linked list
- Returns the total number of nodes
Useful for validation and debugging.

clear()
This function removes every space in the board and frees memory.
Steps:
1. Break the circular link
2. Delete nodes one by one
3. Reset pointers (headNode, tailNode, playerNode) and counters (nodeCount and passGoCount)

#Traversal and Player Movement Logic

The circular linked list makes the board a continuous loop, so the player can keep moving around without hitting the end.
Player Movement process:
1. Roll two dice (sum 2–12)
2. Call movePlayer(roll)
3. The function moves the playerNode forward one node at a time
4. If the player passes the tail node, it counts as passing GO → increment passGoCount
5. The player continues moving til all steps are completed.
The board is circular so the traversal will never reach a null pointer:
Boardwalk -> GO -> Mediterranean Avenue -> ... it will keep looping.





