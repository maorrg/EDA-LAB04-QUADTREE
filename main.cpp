#include "QuadTree.h"


int main() {
	QuadTree qt("./images/feep.pgm");
    cout << "Hola";
    qt.preOrder(qt.getRoot());
    qt.writeTree("./images/feepCompressed.txt");
    
    qt.convertCompressedToPGM("./images/feepCompressed.txt", "./images/feepCompressedFinal.pgm") ;
    
    return 0;
}
