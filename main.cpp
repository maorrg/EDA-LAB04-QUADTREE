#include "QuadTree.h"


int main() {
	QuadTree qt("./images/dragon.txt");
    cout << "Hola";
    qt.preOrder(qt.getRoot());
    qt.writeTree("./images/dragonCompressed.txt");
    return 0;
}
