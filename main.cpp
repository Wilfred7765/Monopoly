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
