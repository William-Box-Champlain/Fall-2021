#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "book.h"
#include <sstream>

using namespace std;
	//default constructor - not actually used but should be implemented anyway
	Book::Book() 
	{
		bName = "";
		bType = UNKNOWN;
		bPages = 0;
		bOunces = 0;
	}
	//constructor
	Book::Book(const string& name, Type type, int pages, float ounces) 
	{
		bName = name;
		bType = type;
		bPages = pages;
		bOunces = ounces;
	}
	string Book::formatReportLine()//return a string with all the info for the book
	{
		stringstream ss;
		string someString;
		ss << bName << "  |" << " Type:" << getTypeName() << " Pages:" << bPages << " Weight (lbs):" << setprecision(3) << getWeightLbs();
		someString = ss.str();
		return someString;
	};  
	float Book::getWeightLbs()//calculate and return the weight of the book in lbs
	{
		int conversionFactor = 16; //ounces/lbs
		return (bOunces / conversionFactor);
	}
	string Book::getTypeName()//return the string which correlates with the book type
	{
		string bookType = TYPE_WORDS[bType];
		return bookType;
	}