#include <iostream>

//---class definition section--- 
//Defines ADT data type Money
//Class exercise
//	Using the following class Money write the following functions.
//	Write function prototype as it would appear in the class, the 
//	function header and body, and a call for the function in the 
//	client program
//
// 415 Muhammed Abubaker Syed


using namespace std;
class Money
{
	friend istream& operator>>(istream& in, Money& tobj);
	friend ostream& operator<<(ostream& out, Money& tobj);
	friend bool operator==(double val, Money& Robj);

    public:
      	Money(int pd = 0, int pc = 0);         //default constructor
      	void setdollars(int pd); 
      	void setcents(int pc);
		Money &operator++();  // why not Money operator++();
		Money operator+(Money Robj);
		bool operator>(Money Robj);
		bool operator==(double val);
		Money operator-(Money Robj);
		Money& operator= (double val);
		Money& operator= (int val);

    private:
        int dollars;
        int cents;
};
