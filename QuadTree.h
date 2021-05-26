#include "Node.h"
#include <vector>

class QuadTree {
private:
    Node* root;
    int height;
    int width;
    int maxVal;
    
    vector<vector<vector<int >>> divideIntoQuadrants(const vector<vector<int>> &pixels) const {
        vector<vector<vector<int>>> fourQuadrants;

        int extraRow = 0, extraColumn = 0;
        if(height % 2 != 0)
            ++extraRow;

        if(width % 2 != 0)
            ++extraColumn;

        for (int i = 0; i < height - extraRow; i+= height / 2 ) {
            for (int j = 0; j < width - extraColumn; j+= width / 2 ){
                vector<vector<int>> matrix;
                for (int k = i; k < height / 2 + i + (i != 0 and extraRow); ++k) {
                    vector<int> row;
                    for (int l = j; l < width / 2 + j + (j != 0 and extraColumn); ++l) {
                        row.push_back(pixels[k][l]);
                        cout << pixels[k][l] << " ";
                    }
                    matrix.push_back(row);
                    row.clear();
                    cout << endl;
                }
                cout<<"+++++" << endl;
                fourQuadrants.push_back(matrix);
                matrix.clear();
            }
        }
        return fourQuadrants;
    }
    
    double averageOfMatrix(const vector<vector<int>> &pixels){
        double sum = 0;
        double count = 0;
        for(int k = 0 ; k < pixels.size() ; ++k ){
            for(int l = 0 ; l < pixels[0].size() ; ++l ){
                sum += pixels[k][l];
                ++count;
            }
        }
        return sum/count;
    }


public:

    QuadTree(int width, int height, int maxVal, vector<vector<int>> pixels) {
        this->width = width;
        this->height = height;
        this->maxVal = maxVal;
        build(pixels);
    }
    
    void print(vector<vector<int>> pixels){
        for(int k = 0 ; k < pixels.size() ; ++k ){
            for(int l = 0 ; l < pixels[0].size() ; ++l ){
                cout << pixels[k][l] << " ";
            }
            cout << endl;
        }
    }


    void build(vector<vector<int>> pixels) {
        root = insert(root, pixels);
    }

    Node* insert(Node* node, vector<vector<int>> pixels){
        vector<vector<vector<int >>> fourQuadrants = divideIntoQuadrants(pixels);

        if(node == nullptr){
            node = new Node();
        }else {
            vector<vector<vector<int >>> fourQuadrants = divideIntoQuadrants(pixels);
            for (int i = 0; i < 4; ++i) {
                //topLeft en primera iteración, topRight en la segunda, bottomLeft en la tercera
                if (averageOfMatrix(fourQuadrants[i]) == 0) {
                    //node->getTurn(i) = new Node(); //valor 0
                } else if (averageOfMatrix(fourQuadrants[i]) == this->maxVal) {
                    node->topLeft = new Node(); //valor 0
                } else {
                    //insert(node->topLeft);
                    //continuar la recursión
                }

            }

        }
        
        return node;
    }
    
    
    








};