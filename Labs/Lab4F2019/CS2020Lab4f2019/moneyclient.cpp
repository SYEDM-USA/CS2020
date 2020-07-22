#include <iostream>
#include "money.h"
#include<fstream>
//
// 415 Muhammed Abubaker Syed

//DO NOT CHANGE ANY CODE EXCEPT THE FILENAME

using namespace std;
int main()
{
    Money M1, M2, M3, M4;
	ofstream outfile;
    
	outfile.open("415moneyout.txt");   // Add your class codes to the file name and close
		// the quote (example:  315_324ratout.txt) where 315 and 324 are your codes

    //========================  # 1 ==========================
    cout << "========  # 1 ===========" << endl;
    cout << "Enter the value 3.45 for M1: ";
    cin >> M1;
    
    cout << "Enter the value 5.05 for M2: ";
    cin >> M2;
    
    cout << "Enter the value 10.95 for M3: ";
    cin >> M3;
	
    //========================  # 2 ==========================
    cout << "========  # 2 ===========" << endl;
	cout << "-------------------\n";
	cout << "Money1 = $" << M1 << endl;
	cout << "Money2 = $" << M2 << endl;
	cout << "Money3 = $" << M3 << endl;
	cout << "-------------------\n";

     //========================  # 3 ==========================
	cout << "========  # 3 ===========" << endl;
    M4 = ++M1; // M1.operator++(); 
	/*Money &Money ::operator++() // the reason we put the & is 
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
	*/


 // M4 = M1++; //M1.operator++(int);
 /*	Money Money::operator++(int)
	{
		Money temp = *this;
		++* this;
		return temp;
	}*/
	cout  << "-------------------\n";
	cout << "M4 = ++M1" << endl;
	cout  << "-------------------\n";
	cout << "Money1 = $" << M1 << endl;
	cout << "Money4 = $" << M4 << endl;
 	cout  << "-------------------\n";
   //========================  # 4 ==========================
	cout << "========  # 4 ===========" << endl;
    M4 = M2 + M2;
	cout  << "-------------------\n";
	cout << "M4 = M2 + M2 " << endl;
	cout << "-------------------\n";
	cout << "Money2 = $" << M2 << endl;
	cout << "Money4 = $" << M4 << endl;
	cout  << "-------------------\n";

    //========================  # 5 ==========================
    cout << "========  # 5 ===========" << endl;
	cout  << "-------------------\n";
    cout << M1 << " > " << M2 << endl;
	if( M1 > M2)
		cout << "True: Not Correct" << endl;
	else
		cout << "False: Correct" << endl;
	cout  << "-------------------\n";

    //========================  #6 ==========================
    cout << "========  # 6 ===========" << endl;
	cout  << "-------------------\n";
    cout << M3 << " == 3.95" << endl;
	if(M3 == 3.95)
		cout << "True: Not Correct" << endl;
	else
		cout << "False: Correct" << endl;
	cout << "-------------------\n";

   //========================  # 7 ==========================
    cout << "========  # 7 ===========" << endl;
	cout  << "-------------------\n";
    cout  << " 10.95 == " << M3  << endl;
    if(10.95 == M3)
		cout << "True: Correct" << endl;
	else
		cout << "False: Not Correct" << endl;
	cout << "-------------------\n";

    //========================  # 8 ==========================
	cout << "========  # 8 ===========" << endl;
    M1 = M3 - M2;
	cout  << "-------------------\n";
	cout << "M1 = M3 - M2; " << endl;
	cout << "Money1 = $" << M1 << endl;
    cout << "Money2 = $" << M2 << endl;
	cout << "Money3 = $" << M3 << endl << endl;
	cout  << "-------------------\n";

   //========================  # 9 ==========================
	cout << "========  # 9 ===========" << endl;
	cout  << "-------------------\n";
    M3 = 1.59;
    cout << "M3 = 1.59" << endl;		
    cout << "Money3 = $" << M3 << endl;
	cout  << "-------------------\n";

  //========================  # 10 ==========================
	cout << "========  # 10 ===========" << endl;
    M3 = 25;
	cout  << "-------------------\n";
    cout << "M3 = 25" << endl;		
    cout  << "-------------------\n";
	cout << "Money3 = $" << M3 << endl;
 	cout  << "-------------------\n";


	//------------------output to a file for grading purposes ------------------------------
	//========================  # 2 ==========================
	outfile << "========  # 2 ===========" << endl;
	outfile << "-------------------\n";
	outfile << "Money1 = $" << M1 << endl;
	outfile << "Money2 = $" << M2 << endl;
	outfile << "Money3 = $" << M3 << endl;
	outfile << "-------------------\n";

	//========================  # 3 ==========================
	outfile << "========  # 3 ===========" << endl;
	M4 = ++M1;
	outfile << "-------------------\n";
	outfile << "M4 = ++M1" << endl;
	outfile << "-------------------\n";
	outfile << "Money1 = $" << M1 << endl;
	outfile << "Money4 = $" << M4 << endl;
	outfile << "-------------------\n";
	//========================  # 4 ==========================
	outfile << "========  # 4 ===========" << endl;
	M4 = M2 + M2;
	outfile << "-------------------\n";
	outfile << "M4 = M2 + M2 " << endl;
	outfile << "-------------------\n";
	outfile << "Money2 = $" << M2 << endl;
	outfile << "Money4 = $" << M4 << endl;
	outfile << "-------------------\n";

	//========================  # 5 ==========================
	outfile << "========  # 5 ===========" << endl;
	outfile << "-------------------\n";
	outfile << M1 << " > " << M2 << endl;
	if (M1 > M2)
		outfile << "True: Not Correct" << endl;
	else
		outfile << "False: Correct" << endl;
	outfile << "-------------------\n";

	//========================  #6 ==========================
	outfile << "========  # 6 ===========" << endl;
	outfile << "-------------------\n";
	outfile << M3 << " == 3.95" << endl;
	if (M3 == 3.95)
		outfile << "True: Not Correct" << endl;
	else
		outfile << "False: Correct" << endl;
	outfile << "-------------------\n";

	//========================  # 7 ==========================
	outfile << "========  # 7 ===========" << endl;
	outfile << "-------------------\n";
	outfile << " 10.95 == " << M3 << endl;
	if (10.95 == M3)
		outfile << "True: Correct" << endl;
	else
		outfile << "False: Not Correct" << endl;
	outfile << "-------------------\n";

	//========================  # 8 ==========================
	outfile << "========  # 8 ===========" << endl;
	M1 = M3 - M2;
	outfile << "-------------------\n";
	outfile << "M1 = M3 - M2; " << endl;
	outfile << "Money1 = $" << M1 << endl;
	outfile << "Money2 = $" << M2 << endl;
	outfile << "Money3 = $" << M3 << endl << endl;
	outfile << "-------------------\n";

	//========================  # 9 ==========================
	outfile << "========  # 9 ===========" << endl;
	outfile << "-------------------\n";
	M3 = 1.59;
	outfile << "M3 = 1.59" << endl;
	outfile << "Money3 = $" << M3 << endl;
	outfile << "-------------------\n";

	//========================  # 10 ==========================
	outfile << "========  # 10 ===========" << endl;
	M3 = 25;
	outfile << "-------------------\n";
	outfile << "M3 = 25" << endl;
	outfile << "-------------------\n";
	outfile << "Money3 = $" << M3 << endl;
	outfile << "-------------------\n";


	outfile.close();
	system("pause");
 return 0;
}
