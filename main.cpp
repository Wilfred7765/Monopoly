#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// MAX_SPACES constant
static const int MAX_SPACES = 40;
// -------------------------------
// Data class
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;
    MonopolySpace() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }
    MonopolySpace(string name, string color, int val, int r) {
        propertyName = name;
        propertyColor = color;
        value = val;
        rent = r;
    }
    bool isEqual(const MonopolySpace other) {
        return propertyName == other.propertyName;
    }
    void print() {
        cout << propertyName
             << " : " << propertyColor
             << " : $" << value
             << " : Rent $" << rent;
    }
};
// -------------------------------
// Template Node class
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};
// -------------------------------
// Circular Linked List class
// Spring 2026 version: traversable board
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;
    Node<T>* playerNode;
    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }
    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        if (nodeCount >= MAX_SPACES)
            return false;
        Node<T>* newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = tailNode = playerNode = newNode;
            newNode->nextNode = headNode;
        } else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        }
        nodeCount++;
        return true;
    }
    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        int added = 0;
        for (T value : values) {
            if (!addSpace(value))
                break;
            added++;
        }
        return added;
    }
    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------
    void movePlayer(int steps) {
        if (playerNode == nullptr)
            return;
        for (int i = 0; i < steps; i++) {
            if (playerNode == tailNode)
                passGoCount++;
            playerNode = playerNode->nextNode;
        }
    }

    void printFromPlayer(int count) {
        if (playerNode == nullptr || count <= 0)
            return;
        Node<T>* current = playerNode;
        for (int i = 0; i < count; i++) {
            current->data.print();
            cout << endl;
            current = current->nextNode;
        }
    }
    int getPassGoCount() {
        return passGoCount;
        // -------------------------------
        // Core D: Controlled Board Display
        // -------------------------------
    }
    void printBoard() {
        if (headNode == nullptr)
            return;
        Node<T>* temp = headNode;
        do {
            temp->data.print();
            cout << endl;
            temp = temp->nextNode;
        } while (temp != headNode);
    }
    // -------------------------------
    // Advanced Option A (Level 1): removeByName
    // -------------------------------
    bool removeByName(string name) {
        if (headNode == nullptr)
            return false;
        Node<T>* current = headNode;
        Node<T>* prev = tailNode;
        do {
            if (current->data.propertyName == name) {
                if (headNode == tailNode) {
                    delete current;
                    headNode = tailNode = playerNode = nullptr;
                } else {
                    prev->nextNode = current->nextNode;
                    if (current == headNode)
                        headNode = current->nextNode;
                    if (current == tailNode)
                        tailNode = prev;
                    if (playerNode == current)
                        playerNode = current->nextNode;
                    delete current;
                }
                nodeCount--;
                return true;
            }
            prev = current;
            current = current->nextNode;
        } while (current != headNode);
        return false;
    }
    // -------------------------------
    // Advanced Option A (Level 1): findByColor
    // -------------------------------
    vector<string> findByColor(string color) {
        vector<string> matches;
        if (headNode == nullptr)
            return matches;
        Node<T>* current = headNode;
        do {
            if (current->data.propertyColor == color)
                matches.push_back(current->data.propertyName);
            current = current->nextNode;
        } while (current != headNode);
        return matches;
    }
    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {
        if (headNode == nullptr)
            return 0;
        int count = 0;
        Node<T>* current = headNode;
        do {
            count++;
            current = current->nextNode;
        } while (current != headNode);
        return count;
    }
    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {
        if (headNode == nullptr)
            return;
        tailNode->nextNode = nullptr;
        Node<T>* current = headNode;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->nextNode;
            delete temp;
        }
        headNode = tailNode = playerNode = nullptr;
        nodeCount = 0;
    }

};
// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}
// -------------------------------
// Board Construction Phase
// -------------------------------

int main() {
    srand(time(0));   // initialize random seed

    CircularLinkedList<MonopolySpace> board;

    vector<MonopolySpace> spaces = {
        MonopolySpace("GO","Special",0,0),
        MonopolySpace("Mediterranean Avenue","Brown",60,2),
        MonopolySpace("Community Chest","Special",0,0),
        MonopolySpace("Baltic Avenue","Brown",60,4),
        MonopolySpace("Income Tax","Tax",0,0),
        MonopolySpace("Reading Railroad","Railroad",200,25),
        MonopolySpace("Oriental Avenue","Light Blue",100,6),
        MonopolySpace("Chance","Special",0,0),
        MonopolySpace("Vermont Avenue","Light Blue",100,6),
        MonopolySpace("Connecticut Avenue","Light Blue",120,8),

        MonopolySpace("Jail / Just Visiting","Special",0,0),
        MonopolySpace("St. Charles Place","Pink",140,10),
        MonopolySpace("Electric Company","Utility",150,0),
        MonopolySpace("States Avenue","Pink",140,10),
        MonopolySpace("Virginia Avenue","Pink",160,12),
        MonopolySpace("Pennsylvania Railroad","Railroad",200,25),
        MonopolySpace("St. James Place","Orange",180,14),
        MonopolySpace("Community Chest","Special",0,0),
        MonopolySpace("Tennessee Avenue","Orange",180,14),
        MonopolySpace("New York Avenue","Orange",200,16),

        MonopolySpace("Free Parking","Special",0,0),
        MonopolySpace("Kentucky Avenue","Red",220,18),
        MonopolySpace("Chance","Special",0,0),
        MonopolySpace("Indiana Avenue","Red",220,18),
        MonopolySpace("Illinois Avenue","Red",240,20),
        MonopolySpace("B. & O. Railroad","Railroad",200,25),
        MonopolySpace("Atlantic Avenue","Yellow",260,22),
        MonopolySpace("Ventnor Avenue","Yellow",260,22),
        MonopolySpace("Water Works","Utility",150,0),
        MonopolySpace("Marvin Gardens","Yellow",280,24),

        MonopolySpace("Go To Jail","Special",0,0),
        MonopolySpace("Pacific Avenue","Green",300,26),
        MonopolySpace("North Carolina Avenue","Green",300,26),
        MonopolySpace("Community Chest","Special",0,0),
        MonopolySpace("Pennsylvania Avenue","Green",320,28),
        MonopolySpace("Short Line","Railroad",200,25),
        MonopolySpace("Chance","Special",0,0),
        MonopolySpace("Park Place","Blue",350,35),
        MonopolySpace("Luxury Tax","Tax",0,0),
        MonopolySpace("Boardwalk","Blue",400,50)
    };

    board.addMany(spaces);
    cout << "Monopoly Board:\n";
    board.printBoard();
    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn
             << " | Rolled: " << roll << endl;
        board.movePlayer(roll);
        cout << "Board view from player (next 5 spaces):\n";
        board.printFromPlayer(5);
        cout << "Player landed on: ";
        board.printFromPlayer(1);
        cout << "Times passed GO: "
             << board.getPassGoCount() << endl;
    }

    return 0;
}