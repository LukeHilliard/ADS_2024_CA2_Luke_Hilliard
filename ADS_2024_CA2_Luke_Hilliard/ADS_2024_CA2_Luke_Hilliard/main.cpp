#include <iostream>
#include <fstream>
#include <list>
#include "TreeMap.h"
#include <string>



void part_2_unique_words();
TreeMap<char, list<string>>& populateTreeMap(list<string>& wordList, TreeMap<char, list<string>>& uniqueWords);

/*
    Using only your own implementation of the TreeMap and BST tree (SET) create an application that
    reads in a text file and organises all of the unique words contained within the file by their first letter.

    When the user runs the programme, they should be able to view
        • The list of letters for which there were words in the file.
        • All of the words associated with a given letter.

    Modify the print methods of the Binary Tree Starter Code for display
*/
TreeMap<char, list<string>>& populateTreeMap(list<string>& wordList, TreeMap<char, list<string>>& uniqueWords)
{

    uniqueWords.printLetters();
    
    return uniqueWords;

}
void part_2_unique_words() 
{
    list<string> wordsFromFile;
    ifstream file("unique_words.txt");
    TreeMap<char, list<string>> uniqueWords;

    if (!file.is_open()) 
        std::cout << "Could not find file" << std::endl;
    else {
        std::string s;
        while(getline(file, s)) {
            wordsFromFile.push_back(s);
            uniqueWords.put(s[0]);
        }
        
        populateTreeMap(wordsFromFile, uniqueWords);

    }

    bool exit = false;
    while (!exit)
    {
        int input;
        std::cout << "Unique Words Menu" << std::endl;
        std::cout << " 1. View Letters\n 2. View All\n-1. Exit" << std::endl;
        std::cout << ": ";
        cin >> input;
        std::cout << std::endl;

        switch (input) {
            case 1:
                uniqueWords.printLetters();
            case 2:
              

            case -1:
                exit = true;
                break;

            default:
                std::cout << "Invalid input, select an option from the menu." << std::endl;
        }
    }

    

}



int main() {

    part_2_unique_words();
    return 0;
}


