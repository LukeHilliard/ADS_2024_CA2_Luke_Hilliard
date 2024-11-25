#include <iostream>
#include "Entity.h"
#include "BinaryTree.h"
#include "TreeMap.h"


int main() {

    BinaryTree<Entity<std::string, int>> bTree;
    Entity<std::string, int> e1("First", 4);
    Entity<std::string, int> e2("Second", 2);
    Entity<std::string, int> e3("Third", 6);
    Entity<std::string, int> e4("Fourth", 8);
    Entity<std::string, int> e5("Fifth", 10);
    Entity<std::string, int> e6("Sixth", 1);
    Entity<std::string, int> e7("Seventh", 7);
    Entity<std::string, int> e8("Eighth", 3);
    Entity<std::string, int> e9("Ninth", 5);
    Entity<std::string, int> e10("Tenth", 9);
 

    bTree.add(e1);
    bTree.add(e2);
    bTree.add(e3);
    bTree.add(e4);
    bTree.add(e5);
    bTree.add(e6);
    bTree.add(e7);
    bTree.add(e8);
    bTree.add(e9);
    bTree.add(e10);

    std::cout << "Using BinaryTree<Entity>" << std::endl;
    std::cout << "Post Order" << std::endl;
    bTree.printPostOrder();

    std::cout << "Pre Order" << std::endl;
    bTree.printPreOrder();

    std::cout << "In Order" << std::endl;
    bTree.printInOrder();

    std::cout << "Root" << std::endl;
    std::cout << bTree.root->getItem() << std::endl;


    std::cout << "Using TreeMap" << std::endl;
    TreeMap<std::string, int> tMap;
    tMap.put("First", 4);
    tMap.put("Second", 2);
    tMap.put("Third", 6);
    tMap.put("Fourth", 8);
    tMap.put("Fifth", 10);
    tMap.put("Sixth", 1);
    tMap.put("Seventh", 7);
    tMap.put("Eighth", 3);
    tMap.put("Ninth", 5);
    tMap.put("Tenth", 9);



    std::cout << "Tree In Order" << std::endl;
    tMap.printTreeInOrder();

    std::cout << "Tree Pre Order" << std::endl;
    tMap.printTreePreOrder();

    std::cout << "Tree Post Order" << std::endl;
    tMap.printTreePostOrder();





    return 0;
}