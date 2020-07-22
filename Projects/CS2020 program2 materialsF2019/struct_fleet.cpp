#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
const int SIZE = 25;
struct Car
{
    string owners;
    string cartype;
    string color;
    int mileage;
    int passengers;
};
void get_cars(Car fleet[], int &ncars);
void show_cars(Car fleet[], int &ncars);
void show_owners(Car fleet[], string cartype, int &ncars);
int get_hi_miles(Car fleet[], int ncars);
int get_avg_miles(Car fleet[], int ncars);


int main()
{
    Car fleet[SIZE];
    int numcars = 0;
    int hipos, avg;

    get_cars(fleet, numcars);
    show_cars(fleet, numcars);

 	show_owners(fleet, "Honda", numcars);
 	show_owners(fleet, "Buick", numcars);
 	show_owners(fleet, "Chevy", numcars);

    avg = get_avg_miles(fleet, numcars);
    cout << endl <<  "The average mileaage is " << avg << endl;

	hipos = get_hi_miles(fleet, numcars );	
    cout << endl << "The car with the highest miles is owned by " << fleet[hipos].owners << " with " 
         << fleet[hipos].mileage  << " miles" << endl;

    system("pause");
    return 0;

}

void get_cars(Car fleet[], int &ncars)
{
    ifstream infile;
    infile.open("incars.txt");

    while(!infile.eof())
    {
	    getline(infile, fleet[ncars].owners);
        getline(infile, fleet[ncars].cartype);
        infile >> fleet[ncars].mileage;
        infile.ignore();
        getline(infile, fleet[ncars].color);
        infile >> fleet[ncars].passengers;
        infile.ignore();
        ncars++;
    }

    infile.close();

}
void show_cars(Car fleet[], int &ncars)
{
    cout << left << setw(15) << "Owners" << setw(8) << "cartype" << setw(8) << "Color" 
        << setw(8) << "Mileage" << setw(8) << "Passenger" << endl;
    cout << setw(15) << "------" << setw(8) << "----" << setw(8) << "-----" 
        << setw(8) << "-------" << setw(8) << "---------" << endl;
    for(int k = 0; k < ncars; k++)
    {
         cout << setw(15) << fleet[k].owners << setw(8) << fleet[k].cartype << setw(8) << fleet[k].color
            << setw(8) << fleet[k].mileage << setw(8) << fleet[k].passengers << endl;
    }
    cout << endl << endl;

}
void show_owners(Car fleet[], string mycartype, int &ncars)
{
    cout << endl << endl << "The " << mycartype << " owners are:" << endl;
    for(int k = 0; k < ncars; k++)
    {   if (fleet[k].cartype == mycartype)
            cout << fleet[k].owners << endl;
    }
}


int get_avg_miles(Car fleet[], int ncars)
{

	int tot = 0;
		
	for(int k = 1; k < ncars; k++)
	{
		tot += fleet[k].mileage;
	}
	return tot/ncars;
}

int get_hi_miles(Car fleet[], int ncars)
{

	int hipos = 0;
	int himiles = -500;
		
	for(int k = 1; k < ncars; k++)
	{
		if (fleet[k].mileage > himiles)
		{
			himiles = fleet[k].mileage;
			hipos = k;
		}

	}
	return hipos;
}



