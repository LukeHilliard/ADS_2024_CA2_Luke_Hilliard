#include <iostream>
#include "Entity.h"
#include "BinaryTree.h"
#include "TreeMap.h"


int main() {

    BinaryTree<Entity<std::string, int>> bTree;
    Entity<std::string, int> e1("Hello", 4);
    Entity<std::string, int> e2("World", 2);
    Entity<std::string, int> e3("Goodbye", 6);

    bTree.add(e1);
    bTree.add(e2);
    bTree.add(e3);

    bTree.printPostOrder();




    return 0;
}