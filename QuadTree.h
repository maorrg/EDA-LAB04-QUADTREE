#include "QuadTreeNode.h"
#include "Pgm.h"
#include <queue>

class QuadTree {
private:
    QuadTreeNode* root;
    vector<vector<int> > pixels;
    int maxValue;
    int width;
    int height;
public:
    QuadTree(string imageName){
        Pgm image = Pgm(imageName);
        this->pixels = image.getImage();
        this->maxValue = image.getMaxValue();
        this->width = image.getWidth();
        this->height = image.getHeight();
        insert();
    }

    void insert(){
        this->root = this->recursiveInsert(0, this->width, 0, this->height);
    }

    QuadTreeNode* recursiveInsert(int xStart, int xEnd, int yStart, int yEnd){
        if(isInsideLimits(xStart, xEnd, yStart, yEnd)) return nullptr;
        auto* topLeftPoint = new Point(xStart, yStart);
        auto* bottomRightPoint = new Point(xEnd, yEnd);
        if(xEnd - xStart == 1 && yEnd - yStart == 1){
            return new QuadTreeNode((double)this->pixels[yStart][xStart], topLeftPoint, bottomRightPoint);
        }
        int xDivided = xStart + (xEnd - xStart) / 2;
        int yDivided = yStart + (yEnd - yStart) / 2;
        //if(xDivided >= 0 && yDivided >=0){
            QuadTreeNode* topLeft = this->recursiveInsert(xStart, xDivided, yStart, yDivided);
            QuadTreeNode* topRight = this->recursiveInsert(xDivided, xEnd, yStart, yDivided);
            QuadTreeNode* bottomLeft = this->recursiveInsert(xStart, xDivided, yDivided, yEnd);
            QuadTreeNode* bottomRight = this->recursiveInsert(xDivided, xEnd, yDivided, yEnd);
            auto isUniqueAndColorAverage = this->getIsUniqueAndcolorAverage(topLeft, topRight, bottomLeft, bottomRight);
            bool isUnique = isUniqueAndColorAverage.first;
            double colorAverage = isUniqueAndColorAverage.second;
            if(isUnique) return new QuadTreeNode(colorAverage, topLeftPoint, bottomRightPoint);
            return new QuadTreeNode(colorAverage, topLeftPoint, bottomRightPoint, topLeft, topRight, bottomLeft, bottomRight);
        //}
    }

    bool isInsideLimits(int xStart, int xEnd, int yStart, int yEnd){
        return ((xStart >= xEnd || yStart >= yEnd) || xStart >= this->width || yStart >= this->height);
    }

    pair<bool, double> getIsUniqueAndcolorAverage(QuadTreeNode* topLeft,QuadTreeNode* topRight,QuadTreeNode* bottomLeft,QuadTreeNode* bottomRight){
        double sumValue = 0;
        bool isUnique = true;
        vector<QuadTreeNode*> validNodes;
        if(topLeft != nullptr) validNodes.push_back(topLeft);
        if(topRight != nullptr) validNodes.push_back(topRight);
        if(bottomLeft != nullptr) validNodes.push_back(bottomLeft);
        if(bottomRight != nullptr) validNodes.push_back(bottomRight);
        if(validNodes.size() == 1)
            return make_pair(true, validNodes[0]->color);
        if(validNodes.empty())
            return make_pair(false, 0);
        int compareColor = validNodes[0]->color;
        for(int i=0; i < validNodes.size(); i++){
            sumValue += validNodes[i]->color;
            if(compareColor != validNodes[i]->color) isUnique = false;
        }
        return make_pair(isUnique, (sumValue / validNodes.size()));
    }

    int getWidth(){
        return this->width;
    }

    int getHeight(){
        return this->height;
    }

    QuadTreeNode *getRoot() const {
        return root;
    }

    void preOrder(QuadTreeNode *node) {
        if(node != nullptr) {
            std::cout << node->bottomRightPoint->x << ", "<< node->bottomRightPoint->y << " | Color: " << node->color << std::endl;
            preOrder(node->topLeft);
            preOrder(node->topRight);
            preOrder(node->bottomLeft);
            preOrder(node->bottomRight);
        }
    }
};