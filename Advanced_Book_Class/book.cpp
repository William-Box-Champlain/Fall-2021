#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "book.h"
#include <sstream>
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
	Book::Book(const string& name, Type type, int pages, float ounces, string& reviews) 
	{
		bName = name;
		bType = type;
		bPages = pages;
		bOunces = ounces;
		bReviews = reviews;
		getReviews(reviewsArray, size);
	}
	string Book::formatReportLine()//return a string with all the info for the book
	{	
		stringstream ss;
		string someString;
		ss << bName << "  |" << " Type:" << getTypeName() << " Pages:" <<  bPages << " Weight (lbs):" << setprecision(3) << getWeightLbs() << " Average stars:" << setprecision(5) << calculateAverageReview() << " Most frequent Review:" << getMostFrequentReview();
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
	void Book::getReviews(int reviewsArray[], int size) 
	{
		ifstream input(bReviews);
		if (input.good()) 
		{
			for (int i = 0; i < size; i++) 
			{
				input >> reviewsArray[i];
			}
		}
	}
	void Book::addReviews(const string& reviewFile) {
		bReviews = reviewFile;
	}
	float Book::calculateAverageReview() {
		//helper variables
		int starWeight = 5;
		int totalStars = 0;
		int totalReviews = 0;
		float averageStars = 0;
		for (int i = 0; i < size; i++) {
			totalStars += (starWeight - i) * reviewsArray[i];
			totalReviews += reviewsArray[i];
		}
		averageStars = (float)totalStars / (float)totalReviews;
		return averageStars;
	}
	int Book::getMostFrequentReview() {
		//helper variables
		int largestCount = 0; //currently known highest number of reviews on a star-count
		int largestStars = 5; //currently known star-count with most reviews
		int largestPossibleStar = 5; //combined with incrimentor to determine number of stars.
		for (int i = 0; i < size; i++) {
			if (largestCount < reviewsArray[i]) {
				largestCount = reviewsArray[i];
				largestStars = largestPossibleStar - i;
			}
		}
		return largestStars;
	}

