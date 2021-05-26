#include "Point.h"

struct Node {

    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Point point;
    int value;
    
    Node(const Point &point, int value) : point(point), value(value) {}
};