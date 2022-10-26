//
//  main.cpp
//  lab3
//
//
//  Modified by: Murat K. Gungor 
//  Thanks to Brian R. Hall
//
/*Author:William Box
Class:CSI-240-01
Assignment:PA 1
Date Assigned:Sept 6th
Due Date:Sept 17th
Description:Build a fancy class about books
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
#include <iostream>
#include <fstream>
#include <string>
#include "book.h"

using namespace std;

int main()
{
	const string FILENAME("books.txt");
   
	ifstream input(FILENAME);
	
	if( input.good() )
	{
		while( !input.eof() )
		{
			string name;
			int type;
			int pages;
			float ounces;
			string reviews;
			getline( input, name );
			input >> type >> pages >> ounces >> reviews;
			input.ignore(INT_MAX, '\n');  //ignore the newline char at the end of the line
        
			//create Book object here!
			Book book(name,(Type)type,pages,ounces,reviews);         
			//write out report line for movie here!
			
			cout << book.formatReportLine() << endl;
		}
	}
	else
	{
		cout << "File not found: " << FILENAME << endl;
	}
   
	system("pause");
	return 0;
}