#include "money.h"
#include <iomanip> 
using namespace std;
//---Money class implementation section
// Definitins of member functions for class Money
//
// 415 Muhammed Abubaker Syed

Money::Money(int pd, int pc)
{
		setdollars(pd);
		setcents(pc);
}

void Money::setdollars(int pd)
{
		dollars = (pd>=0)?pd:0;						
}
void Money::setcents(int pc)
{
    	cents = (pc>=0)?pc:0;
}

istream& operator>>(istream& in, Money& tobj)
{
	double temp;
	in >> temp;
	temp = temp * 100;
	tobj.dollars = int(temp / 100);
	tobj.cents = int(temp) % 100;

	return in; //return a ref. to istream to allow
                //chaining of function calls

}

ostream& operator<<(ostream& out, Money& tobj)
{
	double temp;
	temp = tobj.dollars * 100;
	temp = temp + tobj.cents;
	temp = temp / 100;
	out <<fixed<<setprecision(2)<< temp ;
	return out;
}
Money &Money ::operator++() // why not Money Money ::operator++()
{
	
	if (cents == 99)
	{
		cents = 00;
		dollars += 1;
	}
	else
		cents++;
	return *this;
}

Money Money::operator+(Money Robj)
{
	Money temp;
	if (cents + Robj.cents > 99)
	{
		temp.cents = cents + Robj.cents;
		temp.cents = temp.cents - 100;
		temp.dollars += 1;

	}
	else
		temp.cents = cents + Robj.cents;
	temp.dollars = dollars + Robj.dollars;

	return temp;
}

bool Money :: operator>(Money Robj)
{
	if(dollars>Robj.dollars)
		{
		return true;
		}
	if (dollars == Robj.dollars)
	{
		if (cents > Robj.cents)
		{
			return true;
		}
	}
	return false;
}
bool Money :: operator==(double val)
{
	int valdollar;
	val = val * 100;
	valdollar = int(val / 100);

	if (dollars == valdollar)
		return true;
	return false;
}

 bool operator==(double val, Money& Robj)
{
	 int valdollar;
	 val = val * 100;
	 valdollar = int(val / 100);

	 if (Robj.dollars == valdollar)
		 return true;

	 return false;
}

 Money Money ::operator-(Money Robj)
 {
	 
	 Money	temp;
	 /*
	 if (Robj.dollars > dollars)
	 {
		 if (Robj.cents > cents)
		 {
			 temp.dollars =  dollars- Robj.dollars ;
			 temp.cents =  cents - Robj.cents;
		 }
		 else if (Robj.cents < cents)
		 {

		 }
		 if (Robj.cents == cents)
		 {

		 }
	 }
	 else if (Robj.dollars < dollars)
	 {
			if (Robj.cents > cents)
			{

			}
			else if (Robj.cents < cents)
			{

			}
			if (Robj.cents == cents)
			{

			}
	 }
	 else
	 {
		 if (Robj.cents > cents)
		 {

		 }
		 else if (Robj.cents < cents)
		 {

		 }
		 else
		 {

		 }
	 }
	 */

	 temp.dollars = dollars - Robj.dollars;
	 temp.cents = cents - Robj.cents;
	 return temp;


 }

 Money& Money:: operator= (double val)
 {
	 val = val * 100;
	 dollars = int(val / 100);
	 cents = int(val) % 100;

	 return *this;
 }
 Money& Money::operator= (int val)
 {
	 dollars = val;
	 cents = 0;
	 return *this;
 }
