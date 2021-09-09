//
//  programmer.cpp
//  lab2
//
//  Created by Brian R. Hall on 1/3/14.
//  Copyright (c) 2014 Brian R. Hall. All rights reserved.
//

#include "programmer.h"

//implement functions here!

//returns the number of programmers - fills in the programmers array from the ifstream
int readProgrammers( ifstream& inputFile, Programmer programmers[], int maxProgrammers )
{	
	//helper variables
	int TempOne = 0;
	int TempTwo = 0;
	string TempName = "";
	string TempString = "";
	//read from ifstream into programmer struct
	for(int i = 0; i < maxProgrammers; i++)
	{
		getline(inputFile, TempString);
	}
	return 0;
}

//returns the total of the lines field for all programmers
int calcTotalLines( Programmer programmers[], int numProgrammers )
{
	//helper variables
	int Total = 0;
	//just a stub!
		for (int i = 0; i < numProgrammers; i++) {
			Total += programmers.lines[i];
	}
	return Total;
}

//returns the average lines coded for all programmers as a float
float calcAverageLines( Programmer programmers[], int numProgrammers )
{
	//helper variables
	int Total = 0;
	float Average = 0.0f;
	//just a stub!
	for (int i = 0; i < numProgrammers; i++) {
		Total += programmers.lines[i];
	}
	Average = Total / numProgrammers;
	return Average;
}

//return a string containing info for a particular programmer
string generateProgrammerInfo( Programmer theProgrammer )
{
	//just a stub!
	return "";
}

//generate report for all programmers
//call calcTotalLines, calcAverageLines, and generateProgrammerInfo functions
void generateProgrammerReport( ostream& output, Programmer programmers[], int numProgrammers )
{
	//helper variables
	int Total = 0;
	float Average = 0;
	//just a stub!
	Total = calcTotalLines(programmers,numProgrammers);
	Average = calcAverageLines(programmers, numProgrammers);	
	output << "These are all the programmers:";
	generateProgrammerInfo;
	for( int i = 0; i < numProgrammers; i++ )
	{
		output << "\nProgrammer info"; //this should output the programmer info for each programmer
	}
   
	output << "\nTotal lines = " << Total; //this should ouptut the total lines
	output << "\nAverage lines = " << Average; //this should output the average lines
	output << endl;
}