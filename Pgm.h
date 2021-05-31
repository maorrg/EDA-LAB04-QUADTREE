//
// Created by Christian Ledgard on 25/05/21.
//

#ifndef EDA_LAB04_QUADTREE_PGM_H
#define EDA_LAB04_QUADTREE_PGM_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class Pgm{
    
    int height;
    int width;
    int maxValue;
    vector<vector<int> > image;

    void read(string filePath){
        string line;
        ifstream myfile(filePath);
        if (myfile.is_open()){
            stringstream ss;
            string inputLine;

            getline(myfile,inputLine);
            if(inputLine != "P2")
                std::cerr << "Version error" << endl;

            getline(myfile,inputLine);
            std::cout << "Comment : " << inputLine << endl;

            ss << myfile.rdbuf();
            ss >> this->width >> this->height >> this->maxValue;
            
            for(int row = 0; row < this->height; ++row){
                vector<int> rowImage;
                for (int col = 0; col < this->width; ++col){
                    int tempVal;
                    ss >> tempVal;
                    rowImage.emplace_back(tempVal);
                }
                this->image.emplace_back(rowImage);
                rowImage.clear();
            }
            myfile.close();
        }
    }

public:
    Pgm(string fileName) {
        read(fileName);
    }
    
    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }

    int getMaxValue() const {
        return maxValue;
    }

    const vector<vector<int>> &getImage() const {
        return image;
    }


};

#endif //EDA_LAB04_QUADTREE_PGM_H
