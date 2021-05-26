#include <iostream>
#include "Pgm.h"
#include "QuadTree.h"

using namespace std;

int main() {
    
    Pgm pgmFile1("dragonin.txt");
    
    QuadTree qt(pgmFile1.getWidth(), pgmFile1.getHeight(), pgmFile1.getImage());
    
    
    
    return 0;
}