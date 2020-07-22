// This program calls the Time class.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {

	friend istream& operator>> (istream& in, Time& Tobj);
	friend ostream& operator<< (ostream& out, Time& Tobj);

private:
	int Hour;
	int Minute;
public:
	Time(int phh = 0, int pmm = 0);
	void SetTime(int phh, int pmm);
	void addoneMinute();
	void showmealtime();
	Time& operator ++();
	Time operator+(int rval);
	int operator-(Time Robj);
	bool operator>(Time Robj);
	bool operator==(Time Robj);

	int gethour();
	void display();

};
