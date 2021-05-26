#include "Point.h"

struct Node {

    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Point point;
    int value;

    Node() {}

    Node(const Point &point, int value) : point(point), value(value) {}
    
    Node* getTurn(int n){
        switch(n){
            case 0:
                return this->topLeft;
            case 1:
                return this->topRight;
            case 2:
                return this->bottomLeft;
            case 3:
                return this->bottomRight;
        }
        
    }
};