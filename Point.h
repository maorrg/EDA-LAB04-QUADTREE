#include <string>

struct Point {
    int x;
    int y;

    Point(){}
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    std::string exportData(){
        return std::to_string(x) + " " + std::to_string(y);
    }
    
};