// distributionMapcpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <fstream>


class DistributionMap {
	std::map<int, int> map;							// private member
public:
	DistributionMap();								// define the constructor
	void Increment(int);							// define the increment method
	std::string Print();							// define the print method
};

DistributionMap::DistributionMap()					// public constructor
{
													// we may need to initialize the internal map member
													// we might also need a destructor to deallocate it
}

void DistributionMap::Increment(int key) {	
	if (map.find(key) == map.end())					// check if the map contains the key
	{
		map[key] = 1;								// if the key doesnt exist, initialize to 1
	}
	else
	{
		map[key] += 1;								// if the key exists, increment
	}
}

std::string DistributionMap::Print()				// print in JSON form
{
	std::string result = "{ \r\n";					// add a bracket & newline
	for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
	{												// iterate over the map
		result.append("\"");						// "		add quote
		result.append(std::to_string(it->first));	// "0		add key
		result.append("\": ");						// "0":		add quote, colon, & space
		result.append(std::to_string(it->second));	// "0": 12	add value
		result.append(",\r\n");						// "0": 12,	add comma and newline
	}
	result.append("}");								// add closing bracket
	return result;									// return the JSON string
}

int main()
{
	DistributionMap map;
	for (int index = 1; index <= 10000; ++index) {	// 10k iterations		
		map.Increment((rand() % 10 + 1));			// increment the counter for random on the range 1 - 10
	}												// might need to seed the randomizer

	std::ofstream output;							// create a file stream
	output.open("output.json");						// open the file stream
	output << map.Print();							// write to the stream
	output.close();									// close the stream

	return 0;
}
