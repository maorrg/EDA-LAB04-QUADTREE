#include "Node.h"
#include <vector>

class QuadTree {
private:
    Node* head;
    int width;
    int height;
    

public:



    QuadTree(int width, int height, vector<int> pixels) {
        this->width = width;
        this->height = height;
        build(pixels);

    }
    
    void build(vector<int> pixels) {
        for(int i=0; i < width; i++) {
            for(int j=0; j < height; j++) {
                
            }
        }
    }
    
    








};