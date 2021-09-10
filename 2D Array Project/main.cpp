//
//  main.cpp
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
#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"

using namespace std;

int main()
{
	const int MAX_LANGUAGES = 15;
	const string LANGUAGE_NAMES_FILE = "languages.txt";
	const string INFO_FILE = "info.txt";
	
	string names[MAX_LANGUAGES];
	int infoArray[MAX_LANGUAGES][INFO];
   
	int numLanguages = loadLanguages( LANGUAGE_NAMES_FILE, names, MAX_LANGUAGES );
	
	if( numLanguages > 0 )
	{
		bool infoLoaded = loadInfo( INFO_FILE, infoArray, numLanguages );
		if( infoLoaded )
		{
         cout << setw(15) << left << "Name: " << setw(10) << left << "| Rank:" << "| Year Released:" << endl;
         
         for( int i = 0; i < numLanguages - 1; i++ )
			{
				cout << formatReportLine( i, infoArray, names ) << endl;
			}
			cout << "\nThese are programming languages listed by date and \"quality rank\". " << endl;
			cout << "If you do not agree, consult XKCD.";
		}
	}
   
   return 0;
}

