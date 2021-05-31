#include "QuadTree.h"


int main() {
	QuadTree qt("./images/feep.txt");
    cout << "Hola";
    qt.preOrder(qt.getRoot());
    return 0;
}
