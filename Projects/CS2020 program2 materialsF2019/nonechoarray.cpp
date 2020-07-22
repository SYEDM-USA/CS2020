#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAXITEMS = 100;
int gettotal( int items[], int numitems);
void printitems( string itemnames[], int items[], int numitems);
int main()
{
	int total = 0, numitems = 0;
	int items[MAXITEMS];
	string itemnames[MAXITEMS];
	string name;
	cout <<"Enter a name or q to quit: ";
	getline (cin, name);

	

    while (name != "q")
    {   
		itemnames[numitems] = name;
		cout << "Enter a value for " << name << " : ";
        cin >> items[numitems];
		

		cin.ignore(); // (between cin >> and getline)

		cout <<"Enter a name or q to quit: ";
		getline (cin, name);

		numitems++;
		
    }
    printitems(itemnames, items, numitems);
    total = gettotal(items, numitems);
    cout << endl << "The total is " << total << endl;
 	return 0;
}

int gettotal( int items[], int numitems)
{
        int tot = 0, k;

        for (k = 0; k < numitems; k++)
        {   tot += items[k];
        }
        return tot;
}
void printitems( string itemnames[], int items[], int numitems)
{   
    int k;

    cout << setw(3) << "sub" << setw(10) << "Items" << endl;
    for (k = 0; k < numitems; k++)
    {   cout << setw(3) << k << setw(10) << itemnames[k] << setw(10) << items[k] << endl;
    }
}
