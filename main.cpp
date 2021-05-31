#include "QuadTree.h"


int main() {
	QuadTree qt("./images/dragon.pgm");
    qt.preOrder(qt.getRoot());
    qt.writeTree("./images/dragonCompressed.txt");
    
    qt.convertCompressedToPGM("./images/dragonCompressed.txt", "./images/dragonCompressedFinal.pgm") ;
    
    return 0;
}
