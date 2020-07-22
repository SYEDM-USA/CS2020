// This program calls the Time class.
#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

//***********************************************************
// place your member function here                          *
//***********************************************************

//cin operator
istream& operator>> (istream& in, Time& Tobj)
{
	char colon;
	in >> Tobj.Hour >> colon >> Tobj.Minute;
	return in;

}
//cout operator 
ostream& operator<< (ostream& out, Time& Tobj)
{
	
	out << Tobj.Hour << ":" << setw(2) << setfill('0') << Tobj.Minute;
	return out;
}


Time::Time(int phh, int pmm)	//this overloaded constructor
{								//will call setTime, so you
	SetTime(phh, pmm);			//can write your code once 
}								// "time" saver

//to set time in correct format function
void Time::SetTime(int phh, int pmm)
{
	if (phh < 0 || phh>23 || pmm < 0 || pmm>59)
	{
		Hour = 0;
		Minute = 0;
	}
	else
	{
		Hour = phh;
		Minute = pmm;
	}
}
//getter function hour
int Time::gethour()
{
	return Hour;
}
// function to add one minute to time
void Time::addoneMinute()
{
	if (Minute == 59 && Hour == 23)
	{
		Minute = 0;
		Hour = 0;
	}
	else if (Minute == 59)
	{
		Minute = 0;
		Hour += 1;
	}
	else
		Minute += 1;
}

// function to show meal time
void Time::showmealtime()
{
	if (Hour == 7)
	{
		cout << "Breakfast Time";
	}
	else if (Hour == 12)
	{
		cout << "Lunch Time";
	}
	else if (Hour == 17)
	{
		cout << "Dinner Time";
	}
	else
		cout << "No Meal?";
}
// display function 
void Time::display()
{
	cout << Hour << ":" << setw(2) << setfill('0') << Minute << endl;
}

// operator overloading ++
Time& Time ::operator ++()
{
	if (Minute == 59)
	{
		if (Hour == 23)
		{
			Hour = 0;
			Minute = 0;
		}
		else
		{
			Hour += 1;
			Minute = 0;
		}
	}
	else
	{
		Minute += 1;
	}
	return *this;
}
// operator overloading +
Time Time::operator+(int rval)
{
	Time Temp;
	int total;
	total = Hour * 60 + Minute;
	total += rval;
	Temp.Hour = total / 60;
	Temp.Minute = total % 60;

	return Temp;
}

//operator overloading -
int Time:: operator-(Time Robj)
{
	
	Time Temp;
	int total1, total2,temp;
	total1 = Hour * 60 + Minute;
	total2 = Robj.Hour * 60 + Robj.Minute;
	temp = abs(total1 - total2);

	if (*this > Robj)
	{
		return 1440 - temp;
	}
	return temp;

}

// operator overloading >
bool  Time :: operator>(Time Robj)
{
	int temp1, temp2;
	temp1 = Hour * 60 + Minute;
	temp2 = Robj.Hour * 60 + Robj.Minute;
	if (temp1 > temp2)
	{// This function shows that the answer is in correct but I think its an error in the client bcz t2 is not greater than t1
		return true;
	}
	return false;

}

// operator overloading ==
bool Time::operator==(Time Robj)
{
	int temp1, temp2;
	temp1 = Hour * 60 + Minute;
	temp2 = Robj.Hour * 60 + Robj.Minute;
	if (temp1 == temp2)
	{
		return true;
	}
	return false;
}
