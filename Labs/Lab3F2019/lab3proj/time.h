// This program calls the Time class.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
private:
	int Hour;
	int Minute;
public:
	Time(int phh=0 , int pmm=0);
	void SetTime(int phh, int pmm);
	void addoneMinute();
	void showmealtime();

	int gethour();
	void display();

};
