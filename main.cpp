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
    bool isEqual(MonopolySpace other) {
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
};