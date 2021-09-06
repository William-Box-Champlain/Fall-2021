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
	int TempOne = 0;
	int TempTwo = 0;
	// just a stub
	// modify to load the 2D array (infoArray) with the data stored in info.txt
	ifstream input(filename); // create ifstream object and load file
	if(input.is_open()) // confirm that file opened successfully, if so perform loop
	{
		//Loop to traverse rows
		for(int CurrentRow = 0; CurrentRow < Rows; CurrentRow++)
		{
			//loop to traverse columns and input values into 2d array
			for(int CurrentColumn = 0; CurrentColumn < Columns; CurrentColumn++)
			{
				infoArray[CurrentRow][CurrentColumn]
			}
		}
			
	}
	
	return true;
}


string formatReportLine( int languageRank, int infoArray[][INFO], string names[] )
{
	// just a stub
   	// modify to build each output line for each language, and align the output so its organized
   	// hint: to return a string that concatenates strings and ints, use a stringstream
   
   return " ";
}