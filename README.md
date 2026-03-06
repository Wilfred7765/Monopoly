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
**Error message / symptom (if applicable):** Player movement didn’t track passing GO correctly.
**What I tried:** Tested step movement and printing and looping from player node.
**Fix / resolution (or final decision):** Added proper checks for when playerNode reaches tailnodes, and increased passGoCount before the next node
**Commit(s):** Added movePlayer() with GO tracking,printFromPlayer() for player position, and getPassGoCount() method 
---
### Entry 5
**Date:** YYYY-MM-DD
**Entry Type:** Bug Fix / Edge Case / Engineering Decision
**Task worked on:**
**Issue or decision:**
**Error message / symptom (if applicable):**
**What I tried:**
**Fix / resolution (or final decision):**
**Commit(s):**
---
### Entry 6
**Date:** YYYY-MM-DD
**Entry Type:** Bug Fix / Edge Case / Engineering Decision
**Task worked on:**
**Issue or decision:**
**Error message / symptom (if applicable):**
**What I tried:**
**Fix / resolution (or final decision):**
**Commit(s):**
