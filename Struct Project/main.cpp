//
//  main.cpp
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
#include <iostream>
#include <string>
#include <fstream>
#include "programmer.h"

using namespace std;

const int MAX_PROGRAMMERS = 10;

int main()
{
	Programmer programmers[MAX_PROGRAMMERS];
	int numProgrammers = 0;
   
	ifstream inputFile( "programmers.txt" ); // declares file stream and opens for input
   
	if( inputFile.good() )
	{
		numProgrammers = readProgrammers( inputFile, programmers, MAX_PROGRAMMERS );
      
		//close the input file because we are done with it
		inputFile.close();
      
		//report on programmers to console
		generateProgrammerReport( cout, programmers, numProgrammers ); // cout passed as an ostream
      
		//report on programmers to a file
		ofstream outputFile("ProgrammerReport.txt");
		generateProgrammerReport( outputFile, programmers, numProgrammers );
		outputFile.close();
	}
	else
	{
		cout << "File not opened properly!!\n\n";
	}
   
	return 0;
   
}

