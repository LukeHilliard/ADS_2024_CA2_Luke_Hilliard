#include <iostream>
#include <fstream>
#include <string>

#include "Entity.h"
#include "BinaryTree.h"
#include "TreeMap.h"



void part_2_unique_words();

/*
    Using only your own implementation of the TreeMap and BST tree (SET) create an application that
    reads in a text file and organises all of the unique words contained within the file by their first letter.

    When the user runs the programme, they should be able to view
        • The list of letters for which there were words in the file.
        • All of the words associated with a given letter.

    Modify the print methods of the Binary Tree Starter Code for display
*/

void part_2_unique_words() 
{
    ifstream file("unique_words.txt");

    if (!file.is_open()) 
        std::cout << "Could not find file" << std::endl;
    else {
        std::string s;
        while(getline(file, s)) {
            Entity<char, std::string> entry(s[0], s);
            std::cout << entry << std::endl;
        }
    }

    

}



int main() {

    part_2_unique_words();
    return 0;
}


