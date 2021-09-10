//
//  programmer.h
//  lab2
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
	uses a struct array to create an output a list of programmers with their ranks and average lines written

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
#ifndef __lab2__programmer__
#define __lab2__programmer__

#include <string>
#include <fstream>

using namespace std;

struct Programmer
{
	int programmer_id;
	string name;
	int lines; // lines of code programmed
};

//function prototypes

//returns the number of programmers - fills in the programmers array from the ifstream
int readProgrammers( ifstream& inputFile, Programmer programmers[], int maxProgrammers );

//returns the total of the lines field for all programmers
int calcTotalLines( Programmer programmers[], int numProgrammers );

//returns the average lines coded for all programmers as a float
float calcAverageLines( Programmer programmers[], int numProgrammers );

//return a string containing info for a particular programmer
string generateProgrammerInfo( Programmer theProgrammer );

//generate report for all employees
void generateProgrammerReport( ostream& output, Programmer programmers[], int numProgrammers );


#endif /* defined(__lab2__programmer__) */
