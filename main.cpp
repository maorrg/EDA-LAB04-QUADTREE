#include <iostream>
#include "Pgm.h"
#include "QuadTree.h"

using namespace std;

int main() {
    
    Pgm pgmFile1("dragon.pgm");
    
    QuadTree qt(pgmFile1.getWidth(), pgmFile1.getHeight(),pgmFile1.getMaxValue(), pgmFile1.getImage());
    qt.preOrder(qt.getRoot());
    
    
    return 0;
}