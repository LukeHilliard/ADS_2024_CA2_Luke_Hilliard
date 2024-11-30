#pragma once
#include "TreeMap.h"
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
	DataViewer();
	void createIndex();

};