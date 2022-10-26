#pragma once
class Rational
{
public:
	//constructors
	Rational();
	Rational(int p);
	Rational(int p, int q);

	//getter functions
	int getNumerator();
	int getDenominator();
	double getDouble();

	//setter functions
	void setNumerator();
	void setDenominator();

	//Operation functions
	void addRationals(Rational b);
	void subRationals(Rational b);
	void multiRationals(Rational b);
	void diviRationals(Rational b);


private:
	void zeroError();
};