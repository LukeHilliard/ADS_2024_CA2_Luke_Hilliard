#pragma once
#include "TreeMap.h"
#include <sstream> 
#include <iomanip>

/*
Write a C++ application which will allow a user to view and search the data generated in stage 3. Your
application should allow the user to perform each of the following:

	1. Create an index of the data based on any, user-specified field within the data. This should
	also show the user the unique values within that field and the number of rows containing that
	value.
	2. View a subset of the data based on a user-given value for any one of the fields.

All data should be clearly and neatly presented. Efficient memory management must be applied
*/


class DataViewer {
	
	std::string filePath;

public:
	DataViewer(const string file);
	void createIndex();

	template <class T>
	vector<T>& readInCsv(vector<T>& items);

	void run();

	struct Car {
		std::string make;
		std::string model;
		int year;
		int mileage;
		double engineSize;
		std::string fuel;

		friend std::ostream& operator<<(std::ostream& os, const Car& car)
		{		
			os << "" << car.make << " " << car.model << "(" << car.year << ")" << std::endl;
			os << "Mileage: " << std::fixed << std::setprecision(2) << car.mileage << std::endl;
			os << car.engineSize << " " + car.fuel;
			return os;
		} 
	};

};

DataViewer::DataViewer(const string file)
{
	this->filePath = file;
}


// splitting with delimter: https://stackoverflow.com/questions/4533652/how-to-split-string-using-istringstream-with-other-delimiter-than-whitespace
template <class T>
vector<T>& DataViewer::readInCsv(vector<T>& items)
{
	
	ifstream file(this->filePath);

	if (!file.is_open())
		std::cout << "Could not find file" << std::endl;
	else {


		std::string line;
		while (getline(file, line)) {
			std::vector<std::string> tokens;
			int pos = 0;
			
			std::cout << line << std::endl;
			while (pos < line.size()) {
				pos = line.find(",");
				tokens.push_back(line.substr(0, pos));
				line.erase(0, pos + 1);
			}
	

			Car car;
			car.make = tokens[0];
			car.model = tokens[1];
			car.year = std::stoi(tokens[2]);
			car.mileage = std::stoi(tokens[3]);
			car.engineSize = std::stod(tokens[4]);
			car.fuel = tokens[5];

			std::cout << car << "\n" << std::endl;
			
			

			
			
			//items.push_back(car);
		}
			
	}
		
	return items;

}

void DataViewer::run()
{
	vector<Car> cars;
	readInCsv(cars);
	


}