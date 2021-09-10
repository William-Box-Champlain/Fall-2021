//
//  functions.cpp
//  lab1
//
//  Created by Brian R. Hall on 1/3/14.
//  Copyright (c) 2014 Brian R. Hall. All rights reserved.
//
/*

Author:       William Box
Class : CSI - 240 - 01
Assignment : Lab x
Date Assigned : Sept - 03 - 21
Due Date : Sept - 10 - 21@16:00

Description :
	uses a 2D array to create an output a list of programming languages with their ranks and dates of creation

	Certification of Authenticity :
I certify that this is entirely my own work, except where I have given
fully - documented references to the work of others.I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment :
	-Reproduce this assignment and provide a copy to another member of academic staff;and /or
	-Communicate a copy of this assignment to a plagiarism checking
	service(which may then retain a copy of this assignment on its
		database for the purpose of future plagiarism checking)

*/
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "functions.h"

using namespace std;


int loadLanguages( const string& filename, string names[], int maxLanguages )
{
	int numNames = 0;
   
	ifstream input(filename);
	if( input.is_open() )
	{
		while( !input.eof() && numNames < maxLanguages )
		{
			getline( input, names[numNames] );
			numNames++;
		}
		input.close();
	}
	return numNames;
}


bool loadInfo( const string& filename, int infoArray[][INFO], int numLanguages )
{
	// Helper Variables
	int Rows = numLanguages;
	int Columns = INFO;
	string TempString;
	int TempOne;
	int TempTwo;
	// just a stub
	// modify to load the 2D array (infoArray) with the data stored in info.txt
	ifstream input(filename); // create ifstream object and load file
	if(input.is_open()) // confirm that file opened successfully, if so perform loop
	{
		//Loop to traverse rows
		for(int CurrentRow = 0; CurrentRow < Rows; CurrentRow++)
		{		//Store line in TempString, then break line up and cast into ints to be temporarely held in TempOne and TempTwo
				getline(input,TempString);
				TempOne = stoi(TempString.substr(0,TempString.find(" ")));
				TempTwo = stoi(TempString.substr(TempString.find(" "),TempString.length()));
				infoArray[CurrentRow][0] = TempOne;
				infoArray[CurrentRow][1] = TempTwo;
		}
	}
	return true;
}


string formatReportLine( int languageRank, int infoArray[][INFO], string names[] )
{
	// just a stub
   	// modify to build each output line for each language, and align the output so its organized
   	// hint: to return a string that concatenates strings and ints, use a stringstream
	stringstream ss;
	ss << setw(17) << left << names[languageRank] << setw(10) << left << infoArray[languageRank][0] << infoArray[languageRank][1];
   	return ss.str();
}