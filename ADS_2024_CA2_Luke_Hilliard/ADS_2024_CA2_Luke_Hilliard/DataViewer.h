#pragma once
#include "TreeMap.h"
#include <sstream> 
#include <iomanip>
#include <iomanip>



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
		os << car.engineSize << " " << car.fuel;
		return os;
	}

	Car(std::string make, std::string model, int year, int mileage, double engineSize, std::string fuel)
	{
		this->make = make;
		this->model = model;
		this->year = year;
		this->mileage = mileage;
		this->engineSize = engineSize;
		this->fuel = fuel;
	}

};
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
	std::vector<Car*> cars;

public:
	DataViewer(const string file);

	void viewAll(vector<Car*>& cars);
	void createIndex(vector<Car*>& cars);
	vector<Car*>& readInCsv(vector<Car*>& items);
	void run();
};

DataViewer::DataViewer(const string file)
{
	this->filePath = file;
}


//https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-setprecision#:~:text=How%20to%20set%20precision%20in,from%20the%20header.
vector<Car*>& DataViewer::readInCsv(vector<Car*>& items)
{
	
	ifstream file(this->filePath);

	if (!file.is_open())
		std::cout << "Could not find file" << std::endl;
	else {


		std::string line;
		while (getline(file, line)) {
			std::vector<std::string> tokens;
			int pos = 0;

			//std::cout << line << std::endl;
			while (pos < line.size()) {
				pos = line.find(",");
				tokens.push_back(line.substr(0, pos));
				line.erase(0, pos + 1);
			}


			std::string make = tokens[0];
			std::string model = tokens[1];
			int year = std::stoi(tokens[2]);
			int mileage = std::stoi(tokens[3]);
			double engineSize = std::stod(tokens[4]);
			std::string fuel = tokens[5];

			Car* car = new Car(make, model, year, mileage, engineSize, fuel);

			//std::cout << car << "\n" << std::endl;

			items.push_back(car);
		
			
		}
	}
	return items;
}

void DataViewer::createIndex(vector<Car*>& cars)
{
	std::cout << "(make, model, year, mileage, engineSize, fuel)" << std::endl;
	std::cout << "Enter a field to index : ";
	std::string field;
	cin >> field;
	std::cout << std::endl;

	TreeMap<std::string, int> map;

	for (const Car* car : cars) {
		
	}
}

void DataViewer::viewAll(vector<Car*>& cars)
{
	int index = 1;
	for (const Car* car : cars) {
		std::cout << "(" << index << ")" << std::endl;
 		std::cout << *car << "\n" << std::endl;
		index++;
	}
}

void DataViewer::run()
{

	readInCsv(this->cars);
	std::cout << this->cars.size() << std::endl;
	int option;
	std::cout << " 1. View All" << std::endl;
	std::cout << " 2. " << std::endl;
	std::cout << " 3. " << std::endl;
	std::cout << "-1. Return" << std::endl;
	std::cin >> option;

	
	if (option == 1) {
		this->viewAll(this->cars);
	}



}