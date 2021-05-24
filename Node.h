#include "Point.h"

struct Node {

    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Point point;
    int value;

    Node() {
        //DEFAULT CONSTRUCTOR
    }

    Node(Point point, int value) {
        this->point = point;
        this->value = value;
    }
};