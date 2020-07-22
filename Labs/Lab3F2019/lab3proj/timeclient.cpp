// This program calls the Time class.
#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

int main()
{
    int k, temphrs, tempmins, freehour, bghour;                               
    char colon; //used to skip over the colon in the input
    //Code for #1 goes here
    //Creating objects
    Time FreeTime;
    Time WrongTime(25,45);
    Time BGTime(7,30);


    cout << "FreeTime:";
    FreeTime.display();      //Add the code for #2 to display  FreeTime
    cout << endl;

	cout << "WrongTime:";
    WrongTime.display();            //Add the code for #2 to display  WrongTime
    cout << endl;

    cout << "BGTime:";
    BGTime.display();     //Add the code for #2 to display  BGTime
    cout << endl;
  
    //Here is the code for #3's input
    cout << "Please enter the time in the form HH:MM: ";
    cin >> temphrs >> colon >> tempmins;
   //Add the code for #3 to fill the object with the input values
	FreeTime.SetTime(temphrs, tempmins);

	
	cout << endl;


    cout << "FreeTime: ";
    FreeTime.display();         //Add the code for #4 to display  FreeTime
    cout << endl;

	for (k = 0; k < 150; k++)
	{	//Add the code for #5 to to add 150 minutes to FreeTime
		//using this for loop
		FreeTime.addoneMinute();

	}
    cout << "FreeTime:";
    FreeTime.display();           //Add the code for #6 to display  FreeTime
    cout << endl;

    cout << "FreeTime's mealtime  : ";

    FreeTime.showmealtime();         //Add the code for #7 to display FreeTime's mealtime
    cout << endl;

	cout << "WrongTime's mealtime : " ;
    WrongTime.showmealtime();          //Add the code for #7 to display WrongTime's mealtime
    cout << endl;

    	cout << "BGTime's mealtime    : ";
    BGTime.showmealtime();       //Add the code for #7 to display BGTime's mealtime
    cout << endl;

    //Add the code for #8, I have given you the output statements
    // to build your code around!
    if (BGTime.gethour()==FreeTime.gethour())
    {
        cout << "BG Time is Free Time!" << endl;
    }
    if (BGTime.gethour()<FreeTime.gethour())
    {
        cout << "Free Time Soon!" << endl;
    }
    if (BGTime.gethour()>FreeTime.gethour())
    {
        cout << "Free Time is OVER!" << endl;
    }

    return 0;
}