//
//  functions.cpp
//  lab1
//
//  Created by Brian R. Hall on 1/3/14.
//  Copyright (c) 2014 Brian R. Hall. All rights reserved.
//

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "functions.h"
#include <iostream>

using namespace std;


int loadLanguages( const string& filename, string names[], int maxLanguages )
{
	int numNames = 0;
   
	ifstream input(filename);
	if( input.is_open() )
	{	
		cout << input.is_open();
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
		{		//Store line in TempString, then break line up and cast into ints
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
	ss << infoArray[languageRank][0] << infoArray[languageRank][1];
   	return names[languageRank] + ss.str();
}