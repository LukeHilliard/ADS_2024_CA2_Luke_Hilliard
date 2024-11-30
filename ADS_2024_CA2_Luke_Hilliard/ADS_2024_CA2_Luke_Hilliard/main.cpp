#include "FileReader.h"
#include "DataViewer.h"
int main()
{
	bool exit = false;
	while (!exit)
	{
		int choice = 0;
		std::cout << " 1. File Reader" << std::endl;
		std::cout << " 2. Data Viewer" << std::endl;
		std::cout << "-1. Exit" << std::endl;
		std::cout << ": ";
		std::cin >> choice;
		std::cout << std::endl;


		if (choice == 1)
		{
			FileReader reader("unique_words.txt");
			reader.run();
		}
		else if (choice == 2)
		{
			DataViewer viewer("dataProject.csv");
			viewer.run();
		}
		else if (choice == -1)
		{
			exit = true;
		}
		else
		{
			std::cout << "Invalid input. Enter a number representing an option from the menu." << std::endl;
		}
	}

}