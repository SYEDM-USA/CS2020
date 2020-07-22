// This program calls the Time class.
#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

//***********************************************************
// place your member function here                          *
//***********************************************************

Time::Time(int phh, int pmm)	//this overloaded constructor
{								//will call setTime, so you
	SetTime(phh, pmm);			//can write your code once 
}								// "time" saver

void Time:: SetTime(int phh, int pmm)
{
	if(phh<0 || phh>23 || pmm < 0 || pmm>59)
	{
		Hour = 0;
		Minute = 0;
	}
	else
	{
		Hour=phh;
		Minute = pmm;
	}
}
int Time::gethour()
{
	return Hour;
}
void Time::addoneMinute()
{
	if (Minute==59 && Hour==23)
	{
		Minute =0;
		Hour =0;
	}
	else if(Minute==59)
	{
		Minute =0;
		Hour +=1;
	}
	else
		Minute+=1;
}

void Time::showmealtime()
{
	if (Hour==7)
	{
		cout<<"Breakfast Time";
	}
	else if(Hour==12)
	{
		cout<<"Lunch Time";
	}
	else if (Hour==17)
	{
		cout<<"Dinner Time";
	}
	else
		cout<<"No Meal?";
}

void Time::display()
{
	cout  << Hour << ":" << setw(2) << setfill('0') << Minute << endl; 
}
