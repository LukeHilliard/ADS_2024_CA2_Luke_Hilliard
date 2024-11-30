#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "TreeMap.h"


/*
    Using only your own implementation of the TreeMap and BST tree (SET) create an application that
    reads in a text file and organises all of the unique words contained within the file by their first letter.

    When the user runs the programme, they vectorshould be able to view
        • The list of letters for which there were words in the file.
        • All of the words associated with a given letter.

    Modify the print methods of the Binary Tree Starter Code for display
*/
class FileReader {

	string filePath;

public:
	FileReader(string filePath);
	TreeMap<char, vector<string>>& populateTreeMap(vector<string>& wordList, TreeMap<char, vector<string>>& uniqueWords);
	void displayWordList(const vector<string>& words);
	void run();
};


FileReader::FileReader(string file)
{
	this->filePath = file;
}

TreeMap<char, vector<string>>& FileReader:: populateTreeMap(vector<string>& wordList, TreeMap<char, vector<string>>& uniqueWords)
{
    for (const string word : wordList)
    {
        char firstLetter = word[0];
        if (uniqueWords.containsKey(firstLetter))
        {
            uniqueWords.get(firstLetter).push_back(word);
        }
        else
        {
            vector<string> emptyList;
            uniqueWords.put(firstLetter, emptyList);
        }
    }
    return uniqueWords;
}

void FileReader::displayWordList(const vector<string>& words)
{
    std::cout << "[ ";
    for (int i = 0; i < words.size(); i++)
    {
        if (i != words.size() - 1)
            std::cout << words[i] << ", ";
        else
            std::cout << words[i];
    }
}

void FileReader::run()
{
    vector<string> wordsFromFile;
    ifstream file(this->filePath);
    TreeMap<char, vector<string>> uniqueWords;

    if (!file.is_open())
        std::cout << "Could not find file" << std::endl;
    else {
        std::string s;
        while (getline(file, s)) {
            wordsFromFile.push_back(s);
        }

        populateTreeMap(wordsFromFile, uniqueWords);
    }

    bool exit = false;
    do
    {
        int input;
        std::cout << "Unique Words Menu" << std::endl;
        std::cout << " 1. View Letters\n 2. View All By Letter\n-1. Exit" << std::endl;
        std::cout << ": ";
        cin >> input;
        std::cout << std::endl;

        switch (input) {
        case 1: {
            BinaryTree<char> identifiers = uniqueWords.keySet();
            identifiers.printInOrder();
            break;
        }

        case 2: {
            char key;
            std::cout << "Enter a letter: ";
            std::cin >> key;
            std::cout << std::endl;
            if (uniqueWords.containsKey(key))
            {
                displayWordList(uniqueWords.get(key));
            }
            break;
        }

        case -1: {
            exit = true;
            break;
        }

        default: {
            std::cout << "Invalid input, select an option from the menu." << std::endl;
            break;
        }
        }
    } while (!exit);
   
}
