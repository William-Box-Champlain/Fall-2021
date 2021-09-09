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
	int i = 0;
	int TempId = 0;
	int TempLines = 0;
	string TempName = "";
	string TempString = "";
	//read from ifstream into programmer struct
	for(i = 0; i < maxProgrammers; i++)
	{
		getline(inputFile, TempString);
		TempId = stoi(TempString.substr(0, TempString.find(" ")));
		TempString.erase(0, (TempString.find(" ") + 1));
		TempName = TempString.substr(0, TempString.find(" "));
		TempLines = stoi(TempString.substr(TempString.find(" "), TempString.length()));
		programmers[i].lines = TempLines;
		programmers[i].name = TempName;
		programmers[i].programmer_id = TempId;
	}
	return i;
}

//returns the total of the lines field for all programmers
int calcTotalLines( Programmer programmers[], int numProgrammers )
{
	//helper variables
	int Total = 0;
	//just a stub!
		for (int i = 0; i < numProgrammers; i++) {
			Total += programmers[i].lines;
	}
	return Total;
}

//returns the average lines coded for all programmers as a float
float calcAverageLines( Programmer programmers[], int numProgrammers )
{
	int Total = calcTotalLines(programmers, numProgrammers);
	float Average = 0.0f;
	Average = Total / numProgrammers;
	return Average;
}

//return a string containing info for a particular programmer
string generateProgrammerInfo( Programmer theProgrammer )
{
	return to_string(theProgrammer.programmer_id) + " " + theProgrammer.name + " " + to_string(theProgrammer.lines);
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
	for( int i = 0; i < numProgrammers; i++ )
	{
		output << endl << generateProgrammerInfo(programmers[i]); //this should output the programmer info for each programmer
	}
   
	output << "\nTotal lines = " << Total; //this should ouptut the total lines
	output << "\nAverage lines = " << Average; //this should output the average lines
	output << endl;
}