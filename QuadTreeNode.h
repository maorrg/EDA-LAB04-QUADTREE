#include "Point.h"
#include <string>

struct QuadTreeNode {
    double color;
    QuadTreeNode* topLeft;
    QuadTreeNode* topRight;
    QuadTreeNode* bottomLeft;
    QuadTreeNode* bottomRight;
    Point* topLeftPoint;
    Point* bottomRightPoint;

    QuadTreeNode(){};

    bool isLeaf(){
        if(this->topLeft == nullptr && this->topRight == nullptr && 
            this->bottomLeft == nullptr && this->bottomRight == nullptr) {
            return true;
        }
        return false;
    }

    QuadTreeNode(double color, Point* topLeftPoint, Point* bottomRightPoint){
        this->color = color;
        this->topLeftPoint = topLeftPoint;
        this->bottomRightPoint = bottomRightPoint;
        this->topLeft = nullptr;
        this->topRight = nullptr;
        this->bottomLeft = nullptr;
        this->bottomRight = nullptr;
    }

    QuadTreeNode(double color, Point* topLeftPoint, Point* bottomRightPoint, QuadTreeNode* topLeft, QuadTreeNode* topRight, QuadTreeNode* bottomLeft, QuadTreeNode* bottomRight){
        this->color = color;
        this->topLeftPoint = topLeftPoint;
        this->bottomRightPoint = bottomRightPoint;
        this->topLeft = topLeft;
        this->topRight = topRight;
        this->bottomLeft = bottomLeft;
        this->bottomRight = bottomRight;
    }
    
    std::string exportData(){
        return std::to_string((int)this->color) + " "
        + this->topLeftPoint->exportData() + " "
        + this->bottomRightPoint->exportData();
    }



};