#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 2. MAX_SPACES constant
static const int MAX_SPACES = 40;

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
    int addMany(vector<T> values) {
        int added = 0;
        for (T value : values) {
            if (!addSpace(value))
                break;
            added++;
        }
        return added;
    }
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
    }
};


//     void printBoard() {
//         if (headNode == nullptr)
//             return;
//         Node<T>* temp = headNode;
//         do {
//             temp->data.print();
//             cout << endl;
//             temp = temp->nextNode;
//         } while (temp != headNode);
//     }
// };
//
//     int main() {
//         CircularLinkedList<MonopolySpace> board;
//         vector<MonopolySpace> spaces = {
//             MonopolySpace("Mediterranean Avenue","Brown",60,2),
//             MonopolySpace("Baltic Avenue","Brown",60,4),
//             MonopolySpace("Reading Railroad","Railroad",200,25),
//             MonopolySpace("Oriental Avenue","Light Blue",100,6),
//             MonopolySpace("Vermont Avenue","Light Blue",100,6),
//             MonopolySpace("Connecticut Avenue","Light Blue",120,8),
//             MonopolySpace("St. Charles Place","Pink",140,10),
//             MonopolySpace("Electric Company","Utility",150,0),
//             MonopolySpace("States Avenue","Pink",140,10),
//             MonopolySpace("Virginia Avenue","Pink",160,12),
//             MonopolySpace("Pennsylvania Railroad","Railroad",200,25),
//             MonopolySpace("St. James Place","Orange",180,14),
//             MonopolySpace("Tennessee Avenue","Orange",180,14),
//             MonopolySpace("New York Avenue","Orange",200,16),
//             MonopolySpace("Kentucky Avenue","Red",220,18),
//             MonopolySpace("Indiana Avenue","Red",220,18),
//             MonopolySpace("Illinois Avenue","Red",240,20),
//             MonopolySpace("B. & O. Railroad","Railroad",200,25),
//             MonopolySpace("Atlantic Avenue","Yellow",260,22),
//             MonopolySpace("Ventnor Avenue","Yellow",260,22),
//             MonopolySpace("Water Works","Utility",150,0),
//             MonopolySpace("Marvin Gardens","Yellow",280,24),
//             MonopolySpace("Pacific Avenue","Green",300,26),
//             MonopolySpace("North Carolina Avenue","Green",300,26),
//             MonopolySpace("Pennsylvania Avenue","Green",320,28),
//             MonopolySpace("Short Line","Railroad",200,25),
//             MonopolySpace("Park Place","Blue",350,35),
//             MonopolySpace("Boardwalk","Blue",400,50)
//         };
//         board.addMany(spaces);
//         cout << "Monopoly Board:" << endl;
//         board.printBoard();
//         return 0;
//
//     };