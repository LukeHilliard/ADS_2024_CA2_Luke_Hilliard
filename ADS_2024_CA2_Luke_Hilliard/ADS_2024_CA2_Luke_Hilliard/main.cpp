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
    std::cout << "\n" << std::endl;

    std::cout << "Pre Order" << std::endl;
    bTree.printPreOrder();
    std::cout << "\n" << std::endl;

    std::cout << "In Order" << std::endl;
    bTree.printInOrder();
    std::cout << "\n" << std::endl;

    std::cout << "Root" << std::endl;
    std::cout << bTree.root->getItem() << "\n\n" << std::endl;
    


    std::cout << "Using TreeMap" << std::endl;
    TreeMap<int, std::string> tMap;
    tMap.put(1, "First");
    tMap.put(2, "Second");
    tMap.put(3, "Third");
    tMap.put(4, "Fourth");
    tMap.put(5, "Fifth");
    tMap.put(6, "Sixth");
    tMap.put(7, "Seventh");
    tMap.put(8, "Eighth");
    tMap.put(9, "Ninth");
    tMap.put(10, "Tenth");



    std::cout << "TreeMap containsKey" << std::endl;
    std::cout << (tMap.containsKey(4) ? "True" : "False") << std::endl;


    return 0;
}