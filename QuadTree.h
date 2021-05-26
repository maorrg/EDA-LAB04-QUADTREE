#include "Node.h"
#include <vector>

class QuadTree {
private:
    Node* head;
    int height;
    int width;

vector<vector<int >> get_slice( const vector<vector<int >> &pixels, int h, int w, int i, int j ){
    vector<vector<int >> matrix;

    for(int k = 0 ; k < h ; ++k ){
        vector<int> temp;
        for(int l = 0 ; l < w ; ++l ){
            temp.push_back(pixels[k+i][l+j]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    return matrix;
}

public:

    QuadTree(int width, int height, vector<vector<int>> pixels) {
        this->width = width;
        this->height = height;
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
        vector<vector<vector<int >>> fourCuadrant;
    
        int extraRow = 0, extraColumn = 0;
        if(height%2 != 0)
            ++extraRow;

        if(width%2 != 0)
            ++extraColumn;
        
        for (int i = 0; i < height - extraRow; i+= height/2 ) {
            for (int j = 0; j < width - extraColumn; j+= width/2 ){
                vector<vector<int>> matrix;
                for (int k = i; k < height/2 + i + (i != 0 and extraRow); ++k) {
                    vector<int> row;
                    for (int l = j; l < width/2 + j + (j != 0 and extraColumn); ++l) {
                        row.push_back(pixels[k][l]);
                        cout << pixels[k][l] << " ";
                    }
                    matrix.push_back(row);
                    row.clear();
                    cout << endl;
                }
                cout<<"+++++" << endl;
                fourCuadrant.push_back(matrix);
                matrix.clear();
            }
        }
        
        
        
    }
    
    
    








};