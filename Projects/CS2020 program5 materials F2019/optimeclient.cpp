// This program calls the Time class.
#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

int main()
{
    Time T1, T2, T3, T4;
    int diff;

    //========================  # 7 ==========================
    cout << "========  # 7 ===========" << endl;
    cout << "Enter the value for T1: ";
    cin >> T1;
    
    cout << "Enter the value for T2: ";
    cin >> T2;
    
    cout << "Enter the value for T3: ";
    cin >> T3;
	
    //========================  # 6 ==========================
    cout << "========  # 6 ===========" << endl;
	cout << "-------------------\n";
	cout << "Time 1 = " << T1 << endl;
	cout << "Time 2 = " << T2 << endl;
	cout << "Time 3 = " << T3 << endl;
	cout << "-------------------\n";
      //========================  # 1 ==========================
    cout << "========  # 1 ===========" << endl;
    T4 = ++T3;
    cout  << "-------------------\n";
    cout << endl << "T4 = ++T3" << endl;
    cout << "Time 3 = " << T3 << endl;
    cout << "Time 4 = " << T4 << endl;
    cout  << "-------------------\n";
      //========================  # 2 ==========================
    cout << "========  # 2 ===========" << endl;
	T4 = T2 + 59;
    cout << "-------------------\n";
    cout << "T4 = T2 + 59 " << endl;
    cout << "Time 2 = " << T2 << endl;
    cout << "Time 4 = " << T4 << endl;
    cout << "-------------------\n";


    //========================  # 3A ==========================
    cout << "========  # 3A ===========" << endl;
    diff = T2 - T1;
    cout << "-------------------\n";
    cout << "diff = T2 - T1; " << endl;
    cout << "Time 1 = " << T1 << endl;
    cout << "Time 2 = " << T2 << endl;
    cout << "diff = " << diff << endl;
    cout << "-------------------\n";

     //========================  # 3B ==========================
    cout << "========  # 3B ===========" << endl;
    diff = T1 - T2;
    cout << "-------------------\n";
    cout << "diff = T1 - T2; " << endl;
    cout << "Time 1 = " << T1 << endl;
    cout << "Time 2 = " << T2 << endl;
    cout << "diff = " << diff << endl;
    cout << "-------------------\n";

    //========================  # 4 ==========================
    cout << "========  # 4 ===========" << endl;
    cout << "-------------------\n";
    cout << T2 << " > " << T1 << endl;
	if( T2 > T1)
		cout << "True: Correct" << endl;
	else
		cout << "False: Not Correct" << endl;
    cout << "-------------------\n";


    //========================  # 5 ==========================
    cout << "-------------------\n";
    cout << "========  # 5 ===========" << endl;
    cout << T3 << " == " << T2 << endl;
    if(T3 == T2)
		cout << "True: Not Correct" << endl;
	else
		cout << "False: Correct" << endl;
    cout << "-------------------\n";

  
   
  return 0;
}