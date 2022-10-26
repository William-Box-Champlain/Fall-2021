#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "book.h"
#include <sstream>
/*Author:William Box
Class:CSI-240-01
Assignment:Lab 3
Date Assigned:Sept 6th
Due Date:Sept 17th
Description:Build a simple class about books
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
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