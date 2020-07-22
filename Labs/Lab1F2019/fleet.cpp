#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
const int SIZE = 25;

void get_cars(string owners[], string cartype[], string color[], int mileage[], int passengers[], int &ncars);
void show_cars(string owners[], string cartype[], string color[], int mileage[], int passengers[], int ncars);
void show_owners(string owners[], string cartype[], int ncars);
int get_hi_miles(int mileage[], int ncars);
int get_avg_miles(int mileage[], int ncars);


int main()
{
    string owners[SIZE];
    string cartype[SIZE];
    string color[SIZE];
    int mileage[SIZE];
    int passengers[SIZE];
    int numcars = 0;
    int hipos, avg;

    get_cars(owners, cartype, color, mileage, passengers, numcars);
    show_cars(owners, cartype, color, mileage, passengers, numcars);

 	show_owners(owners, cartype, numcars);
 	show_owners(owners, cartype, numcars);
 	show_owners(owners, cartype, numcars);

    avg = get_avg_miles(mileage, numcars);
    cout << endl <<  "The average mileaage is " << avg << endl;

	hipos = get_hi_miles(mileage, numcars );	
    cout << endl << "The car with the highest miles is owned by " << owners[hipos] << " with " 
         << mileage[hipos]  << " miles" << endl;

    system("pause");
    return 0;

}

void get_cars(string owners[], string cartype[], string color[], int mileage[], int passengers[], int &ncars)
{
    ifstream infile;
    infile.open("incars.txt");

    while(!infile.eof() && ncars < SIZE)
    {
	    getline(infile, owners[ncars]);
        getline(infile, cartype[ncars]);
        infile >> mileage[ncars];
        infile.ignore();
        getline(infile, color[ncars]);
        infile >> passengers[ncars];
        infile.ignore();
        ncars++;
    }

    infile.close();

}
void show_cars(string owners[], string cartype[], string color[], int mileage[], int passengers[], int ncars)
{
    cout << left << setw(15) << "Owners" << setw(8) << "cartype" << setw(8) << "Color" 
        << setw(8) << "Mileage" << setw(8) << "Passenger" << endl;
    cout << setw(15) << "------" << setw(8) << "----" << setw(8) << "-----" 
        << setw(8) << "-------" << setw(8) << "---------" << endl;
    for(int k = 0; k < ncars; k++)
    {
         cout << setw(15) << owners[k] << setw(8) << cartype[k] << setw(8) << color[k]
            << setw(8) << mileage[k] << setw(8) << passengers[k] << endl;
    }
    cout << endl << endl;

}
void show_owners(string owners[], string cartype[], int ncars)
{	string mycartype;
	
	cout << "Enter the car type: ";
	getline(cin, mycartype);
    cout << endl << endl << "The " << mycartype << " owners are:" << endl;
    for(int k = 0; k < ncars; k++)
    {   if (cartype[k] == mycartype)
            cout << owners[k] << endl;
    }
}


int get_avg_miles(int mileage[], int ncars)
{

	int tot = 0;
		
	for(int count = 0; count < ncars; count++)
	{
		tot += mileage[count];
	}
	return tot/ncars;
}

int get_hi_miles(int mileage[], int ncars)
{

	int hipos;
		
	hipos = 0;
		
	for(int count = 1; count < ncars; count++)
	{
		if(mileage[count] > mileage[hipos])
			hipos = count;
					
	}
	return hipos;
}



