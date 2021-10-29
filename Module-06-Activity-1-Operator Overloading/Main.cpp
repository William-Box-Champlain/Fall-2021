#include <iostream>
#include <iomanip> 
#include <string> 

using namespace std;

class Clock {
public:
	Clock(int hour = 0, int minute = 0) {
		this->hour = hour;
		(*this).minute = minute;
	}
	Clock(const Clock& aClock) {
		this->hour = aClock.hour;
		this->minute = aClock.minute;
	}
	//addition functions, to be used with operator+
	Clock addMinutes(const int& aMinute) const{
		int nMinute = minute + aMinute;
		Clock nClock(hour, nMinute);
		nClock.updateValues();
		return nClock;
	}
	Clock addHour(const int& aHour) const{
		int nHour = hour + aHour;
		Clock nClock(nHour, minute);
		nClock.updateValues();
		return nClock;
	}
	//operator+ to add an int minute and return the new clock, does not change the calling object (clock)
	Clock operator+(const int& aMinute) const{
		return addMinutes(aMinute);
	}
	//add clocks functions, to be used with operator+
	Clock addClocks(const Clock& aClock) const {
		Clock nClock(0, 0);
		nClock = addMinutes(aClock.minute);
		nClock = addHour(aClock.hour);
		return nClock;
	}
	//operator+ to concatenate another Clock, and return the new clock, does not change the calling object (clock)
	Clock operator+(const Clock& aClock) const {
		return addClocks(aClock);
	}

	//assignment operator
	//Clock& operator=(const Clock& aClock);

	Clock subMinutes(const int& aMinute) const {
		int nMinute = minute - aMinute;
		Clock nClock(hour, nMinute);
		nClock.updateValues();
		return nClock;
	}
	Clock subHour(const int& aHour) const {
		int nHour = hour - aHour;
		Clock nClock(nHour, minute);
		nClock.updateValues();
		return nClock;
	}
	//operator- to substract time of a clock of the given int minute from the Clock, and return the new clock, does not change the calling object (clock)
	Clock operator-(const int& aMinute) const {
		return subMinutes(aMinute);
	}

	//operator== do both Clocks have the same hour and minute?
	//bool operator==(const Clock& aClock) const;

	friend ostream& operator<<(ostream& out, Clock clock)
	{
		out << setw(2) << setfill('0') << clock.hour << ":" << setfill('0') << setw(2) << clock.minute;
		return out;
	}

	//Input Operator
	//friend istream& operator>>(istream& in, Clock &clock);

	void updateValues() // Credit to Jacob Myers
	{
		int extraHours = minute / 60;
		minute = minute % 60;
		hour += extraHours;
		hour = hour % 24;

		if (minute < 0)
		{
			minute += 60;  //Because of % above, will never be less than -60
			hour--;
		}

		if (hour < 0)
		{
			hour += 24;  //Because of % above, will never be less than -24
		}
	}

private:
	int hour;
	int minute;
};


int main()
{
	Clock clockA(4,45);
	cout << clockA << endl;
	clockA = clockA + 45;
	cout << clockA << endl;
	Clock clockB(1,30);
	cout << clockB << endl;
	Clock clockC = clockA + clockB;
	cout << clockC << endl;
	return 0;
}