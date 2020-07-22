//415 Muhammed Abubaker Syed
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

	//defined constant
const int maxMovies = 50;
	//protypes of the other functions 
void PrintArray(string Title[], int Year[], string Category[], int RunTime[], int numMovies);
void fillArray(string Title[], int Year[], string Category[], int RunTime[], int &numMovies);


//#1 ???????????????????
void FindYear(string Title [],int Year [], int numMovies);
void FindAvgCat(int RunTime[],string Title[],string Category[], int numMovies);
void SortTitle(string Title[], int Year[], string Category[], int RunTime[], int numMovies);





//the main function of the program
int main()
{
      //Initialization and declaration of the Array
      string Title[maxMovies];
      int Year[maxMovies];
      string Category[maxMovies];
      int RunTime[maxMovies];
      //variable definitions
      int numMovies = 0;
       //call for the fillArray function which fills the movie list
      fillArray(Title, Year, Category, RunTime, numMovies);
      //call the print function that displays the movie list
      cout << "=================================" << endl;
      PrintArray(Title, Year, Category, RunTime, numMovies);

//#2
      //call the findYear function that displays the movie list for a given year
      cout << "=============== FindYear ==================" << endl;
      FindYear(Title, Year, numMovies);

	  //call the FindAvgCat function that calculates the average runtime for a given category
	  cout << "================ FindAvgCat =================" << endl;
	  FindAvgCat(RunTime,Title, Category, numMovies);


	  //call the SortTitle function
	  cout << "================ SortTitle =================" << endl;
	  SortTitle(Title, Year, Category, RunTime, numMovies);

	  PrintArray(Title, Year, Category, RunTime, numMovies);

	  system("pause");
  return 0;
}

//#3
//this function fills the array
void fillArray(string Title[], int Year[], string Category[], int RunTime[], int &numMovies)
{
	ifstream infile;

    // open the file with verification
	infile.open("movies.txt");


  //input data until the end of file or the array is full
  while(!infile.eof() && numMovies < maxMovies)
  {
	  getline(infile, Title[numMovies]);
	  infile >> Year[numMovies];
	  infile.ignore();
	  getline(infile, Category[numMovies]);
	  infile >> RunTime[numMovies];
	  infile.ignore();
	  numMovies++;


  }


  infile.close();
}

//#4
//this function prints out the movies in the array
void PrintArray(string Title[], int Year[], string Category[], int RunTime[], int numMovies)
{
    cout << left << setw(5) << "#"  << setw(15) << "Title" << setw(15) 
        << "Year Released" << setw(15) << "Category" 
        << setw(15) << "Running Time" << endl;
  
    cout << setw(5) << "-"  << setw(15) << "-----" << setw(15) 
        << "-------------" << setw(15) << "--------" 
        << setw(15) << "------------" << endl;
     
	for(int i = 0;i < numMovies; i++)
	{
		cout << setw(5) << (i + 1)
			<< setw(15) << Title[i]
			<< setw(15) << Year[i]
			<< setw(15) << Category[i]
			<< setw(15) << RunTime[i] << endl;


	}
	cout << "=================================" << endl;
}

//#5
//Display a list of movies for a given year
//The user will supply the year inside the function, declare any variables
//needed
void FindYear(string Title[],int Year[], int numMovies)
{
	int year,cnt=0;
	cout << "Enter the year of choice: ";
	cin >> year;
	cin.ignore();

    cout << "Movies realeased in the year " << year << endl;
	cout << "-----------------" << endl;
	for (int i = 0; i < numMovies; i++)
	{
		if (Year[i] == year)
		{
			cout << setw(15) << Title[i] << setw(15) << Year[i] << endl;
			cnt++;
		}

	}
	if (cnt == 0)
	{
		cout << "No movies found" << endl;

	}

}


//#7
//Find the average run time for a given category(Drama, Action, etc)
//The user will supply the category inside the function,  declare any variables
//needed.
void FindAvgCat(int RunTime[],string Title[],string Category[], int numMovies)
{
	double cnt=0.0,sum=0.0;
	string category;
	cout << "Enter the category: ";
	getline (cin, category);
	
	cout << "All " << category << " Movies" << endl;
	for (int i = 0; i < numMovies; i++)
	{
		if (Category[i] == category)
		{
			cout << setw(15) << Title[i] << setw(15) << RunTime[i] << endl;
			cnt++;
			sum += RunTime[i];
		}

	}
	if (cnt == 0)
	{
		cout << "No movies found" << endl;
		cout << "The average runtime for " << category << " is 0." << endl;

	}
	else
	{
		cout << "The average runtime for " << category << " is " << sum / cnt<<endl;

	}
}


//#8
//SortTitle will sort all arrays by title in acsending order.
void SortTitle(string Title[], int Year[], string Category[], int RunTime[], int numMovies)
{
	string stemp1,stemp2;
	int temp1, temp2;
	bool sort = false;

	while (!sort)
	{
		sort = true;
		for (int k = 0; k < (numMovies - 1); k++)
		{
			if (Title[k] > Title[k + 1])
			{
				stemp1 = Title[k];
				Title[k] = Title[k + 1];
				Title[k + 1] =stemp1;

				stemp2 = Category[k];
				Category[k] = Category[k + 1];
				Category[k + 1] = stemp2;

				temp1 = Year[k];
				Year[k] = Year[k + 1];
				Year[k + 1] = temp1;

				temp2 = RunTime[k];
				RunTime[k] = RunTime[k + 1];
				RunTime[k + 1] = temp2;


				sort = false;

			}
		}
		numMovies--;
	}



}
