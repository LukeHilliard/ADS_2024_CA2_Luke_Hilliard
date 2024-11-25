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

    std::cout << "Post Order" << std::endl;
    bTree.printPostOrder();

    std::cout << "Pre Order" << std::endl;
    bTree.printPreOrder();

    std::cout << "In Order" << std::endl;
    bTree.printInOrder();

    std::cout << "Root" << std::endl;
    std::cout << bTree.root->getItem() << std::endl;

    T
    return 0;
}