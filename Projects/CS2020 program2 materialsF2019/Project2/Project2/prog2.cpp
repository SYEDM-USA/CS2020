//415 Muhammed Abubaker Syed
// Program 1 October 1
// Purpose:To create the solution for the following 
//         interactive program adding, editing and displaying customer information


#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//
const int MAXCUST = 30;

struct Customer
{
	int id;    	// id
	string name;    // Name
	string zip;     // ZIP code
	double balance; // Account balance
	string lastPay; // Date of last payment
};

int menu();
//Prototypes
void addcust(Customer Array[], int& numcustomer);
void updatecust(Customer Array[], int numcustomer);
int findcust(Customer Array[], int findid, int numcustomer);
void displaycust(Customer Array[], int numcustomer);

int main()
{
	Customer Array[MAXCUST];
	int numcustomer = 0;
	int choice;

	choice = menu();
	while (choice != 4)
	{
		//if choice = 1
		if (choice == 1)
		{
			if (numcustomer < MAXCUST)
			{
				addcust(Array, numcustomer);
			}

		}
		//if choice =2
		else if (choice == 2)
		{
			updatecust(Array, numcustomer);
		}
		//if hoice = 3
		else if (choice == 3)
		{
			displaycust(Array, numcustomer);
		}
		choice = menu();
		
	}
	//if choice =4
	if (choice == 4)
	{
		return 0;
	}

	system("pause");
	return 0;
}
//Displays cutomer information
void displaycust(Customer Array[], int numcustomer)
{
	cout <<left<< setw(3) << "## " << setw(5) << "ID " << setw(15) << "Name " << setw(15) << "Zip " << setw(15) << "Balance " << setw(15) << "Last Pay " << endl;
	cout << setw(3) << "-- " << setw(5) << "-- " << setw(15) << "---- " << setw(15) << "--- " << setw(15) << "------- " << setw(15) << "-------- " << endl;
	for (int k = 0; k < numcustomer; k++)
	{
		cout << setw(3) << k+1 << setw(5) << Array[k].id << setw(15) << Array[k].name << setw(15) << Array[k].zip << setw(15) << Array[k].balance << setw(15) << Array[k].lastPay << endl;
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
// finds customer from array
int findcust(Customer Array[], int findid, int numcustomer)
{
	for (int k = 0; k < numcustomer; k++)
	{
		if (findid == Array[k].id)
		{
			return k;
		}
	}
	return -1;

}
// funtion to update customer information
void updatecust(Customer Array[], int numcustomer) 
{
	int findid;
	cout << "Please enter ID number: ";
	cin >> findid;
	cout << findid << endl;
	findid = findcust(Array, findid, numcustomer);
	if (findid == -1)
	{
		cout << "The customer was not found " << endl;
		updatecust(Array, numcustomer);
	}
	else
	{
		cout << "Please enter ID number: ";
		cin >> Array[findid].id;
		cin.ignore();
		cout << Array[findid].id << endl;

		cout << "Please enter name: ";
		getline(cin, Array[findid].name);
		cout << Array[findid].name << endl;

		cout << "Please enter zipcode: ";
		getline(cin, Array[findid].zip);
		cout << Array[findid].zip << endl;

		cout << "Enter account balance: ";
		cin >> Array[findid].balance;
		cin.ignore();
		cout << Array[findid].balance << endl;
		while (Array[findid].balance < 0)
		{
			cout << "Negative balance not accepted. Try again. " ;
			cin >> Array[findid].balance;
			cin.ignore();
			cout << Array[findid].balance << endl;
		}

		cout << "Enter date of last payment: ";
		getline(cin, Array[findid].lastPay);
		cout << Array[findid].lastPay << endl;
	}
}
// function to add customer
void addcust(Customer Array[], int& numcustomer)
{
	cout << "Please enter ID number: ";
	cin >> Array[numcustomer].id;
	cin.ignore();
	cout << Array[numcustomer].id << endl;
	
	cout << "Please enter name: ";
	getline(cin, Array[numcustomer].name);
	cout << Array[numcustomer].name << endl;

	cout << "Please enter zipcode: ";
	getline(cin, Array[numcustomer].zip);
	cout << Array[numcustomer].zip << endl;

	cout << "Enter account balance: ";
	cin >> Array[numcustomer].balance;
	cin.ignore();
	cout << Array[numcustomer].balance << endl;
	while (Array[numcustomer].balance <0)
	{
		cout << "Negative balance not accepted. Try again. " ;
		cin >> Array[numcustomer].balance;
		cin.ignore();
		cout << Array[numcustomer].balance << endl;
	}
	
	cout << "Enter date of last payment: ";
	getline(cin, Array[numcustomer].lastPay);
	cout << Array[numcustomer].lastPay << endl;

	numcustomer++;

}
// main menu function
int menu()
{
	int choice;

	// Display a menu.
	cout << "------------------------------------\n";
	cout << "1. Enter new account information\n";
	cout << "2. Change account information\n";
	cout << "3. Display all account information\n";
	cout << "4. Exit the program\n\n";
	cout << "------------------------------------\n";
	// Get the user's choice.
	cout << "Enter your choice: ";
	cin >> choice;
	cin.ignore();
	cout << choice << endl;  //echo statement for bglinux

	while (choice < 1 || choice>4)
	{
		cout << "Enter valid choice between 1 and 4: ";
		cin >> choice;
		cin.ignore();
		cout << choice << endl;  //echo statement for bglinux
	}

	return choice;
}