# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)
### Entry 1
**Date:** 2026-03-02
**Entry Type: Engineering Decision
**Task worked on: MonopolySpace and Node classes
**Issue or decision: Set default values and equality check for MonopolySpace
**Error message / symptom (if applicable):**
**What I tried: 
**Fix / resolution (or final decision): Added constructors, print, and isEqual methods; create Node Class
**Commit(s): Class Setup for monopoly
---
### Entry 2
**Date:** 2026-03-03
**Entry Type:** Engineering Decision
**Task worked on:** CircularLinkedList class 
**Issue or decision:** Made circular structure with MAX_SPACES limit, addSpace nodes couldn't be read
**Error message / symptom (if applicable):** 
**What I tried:** Adjusted the Max_Space limit
**Fix / resolution (or final decision):** Move the addSpace function into the class
**Commit(s):** Added CircularLinkedList class with addSpace method
---
### Entry 3
**Date:** 2026-03-04
**Entry Type:** Engineering Decision
**Task worked on:** addMany and printBoard functions
**Issue or decision:** addMany was outside the template class and board object was missing
**Error message / symptom (if applicable):** Template type T was not recognized and board was not declared
**What I tried:** tested moving the function into the class
**Fix / resolution (or final decision):** Moved addMany into CircularLinkedList and called it in main() on the board.
**Commit(s):** Fixed the board and the addMany
---
### Entry 4
**Date:** 2026-03-05
**Entry Type:** Engineering Decision
**Task worked on:** movePlayer, printFromPlayer, and getPassGoCount methods
**Issue or decision:** Needed to move the player and track position and go passes.
**Error message / symptom (if applicable):** Player movement didn’t track passing GO correctly
**What I tried:** Tested step movement and printing and looping from player node.
**Fix / resolution (or final decision):** Added proper checks for when playerNode reaches tailnodes, and increased passGoCount before the next node
**Commit(s):** Added movePlayer() with GO tracking,printFromPlayer() for player position, and getPassGoCount() method 
---
### Entry 5
**Date:** 2026-03-06
**Entry Type:** Engineering Decision
**Task worked on:** removeByName and findByColor features
**Issue or decision:** Create functions to remove property by name and updating pointers, and finds/return all properties with a specific color
**Error message / symptom (if applicable):** Removing the head or tail could break the list or leave bad pointers
**What I tried:** Used a do-while loop and tracked nodes to reconnect the list after deletion
**Fix / resolution (or final decision):** Updated pointers and decreased nodeCount
**Commit(s):** Added removeByName for circular linked list node deletion and findByColor to return property names matching a color
---
### Entry 6
**Date:** 2026-03-07
**Entry Type:** Edge Case
**Task worked on:** Helper functions for circular linked list
**Issue or decision:** Need functions to clear list and count spaces.
**Error message / symptom (if applicable):** Inifinte loops w3hen clearing the list
**What I tried:** Looped through the list and counted each node and break the circular link before deleting nodes
**Fix / resolution (or final decision):** Temporarily broke the circular list, deleted each node one by one then reset
**Commit(s):** Implemented countSpaces and clear methods
---
### Entry 7
**Date:** 2026-03-07
**Entry Type:** Engineering Decision
**Task worked on:** Game loop for player turns
**Issue or decision:** Need to simulate how a player movement
**Error message / symptom (if applicable):** 
**What I tried:** Made a loop that runs 10 times with dice simulation
**Fix / resolution (or final decision):** Used dice to move player then print next 5 spaces and times go is passed
**Commit(s):** Implemented player traverse loop

