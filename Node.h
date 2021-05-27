#include "Point.h"

struct Node {

    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Point point;

    Node() {
        topLeft= nullptr;
        topRight= nullptr;
        bottomLeft= nullptr;
        bottomRight= nullptr;
    }

    explicit Node(const Point &point) : point(point) {
        topLeft= nullptr;
        topRight= nullptr;
        bottomLeft= nullptr;
        bottomRight= nullptr;
    }
    
    Node*& getTurn(int n){
        switch(n){
            case 0:
                return this->topLeft;
            case 1:
                return this->topRight;
            case 2:
                return this->bottomLeft;
            case 3:
                return this->bottomRight;
            default:
                break;
        }
    }
};