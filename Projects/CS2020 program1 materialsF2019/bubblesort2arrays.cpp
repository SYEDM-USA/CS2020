// This program uses the bubble sort algorithm to sort an 
// array in ascending order.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void sortArray(string Names[], int ary[], int elems);
void showArray(string Names[], int ary[], int elems);

int main()
{
	const int SIZE = 6;
    int values[SIZE] = {7, 2, 3, 8, 9, 1};
    string Names[SIZE] = {"Pat", "Bob", "Mary", "Taylor", "Jill", "Frank"};

	cout << "The unsorted values are:\n";
	showArray(Names, values, SIZE);
	sortArray(Names, values, SIZE);
	cout << "The sorted values are:\n";
	showArray(Names, values, SIZE);
	return 0;
}

//***********************************************************
// Definition of function sortArray                         *
// This function performs an ascending-order bubble sort on *
// array. The parameter elems holds the number of elements  *
// in the array.                                            *
//***********************************************************

void sortArray(string Names[], int ary[], int numitems)
{
	int  itemp;
    string stemp;
	bool sort = false;

	
	while (!sort)
	{	sort = true;
		for (int k = 0; k < (numitems - 1); k++)
		{
			if (ary[ k] > ary[ k + 1])
			{
				itemp = ary[ k];
				ary[ k] = ary[ k + 1];
				ary[ k + 1] = itemp;
			

				stemp = Names[ k];
				Names[ k] = Names[ k + 1];
				Names[ k + 1] = stemp;

				sort = false;
			}
		}
		numitems--;
   } 
}

//**************************************************************
// Definition of function showArray                            *
// This function displays the contents of array. The parameter *
// elems holds the number of elements in the array.            *
//**************************************************************

void showArray(string Names[], int ary[], int elems)
{   
    cout << endl << "----------------------------------------------"  << endl;
    cout << setw(10) << "Names" << setw(10) << "Values" << endl;
    cout << setw(10) << "-----" << setw(10) << "------" << endl;
	for (int count = 0; count < elems; count++)
    {	cout << setw(10) << Names[count] << setw(10);
		cout << ary[count];
	    cout << endl;
    }
    cout << endl << "----------------------------------------------" << endl;

}
