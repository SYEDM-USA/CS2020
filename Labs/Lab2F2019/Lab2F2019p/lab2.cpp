//Original code modified from a current student
// 415 Muhammed Abubaker Syed
//Printing category information by taking input from user. 

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//defined struct
struct Shareholder 
{
  string Name;
  string Category;
  int Shares;
};
//defined constant
const int maxclients  = 50;
//protypes of the other functions 
void fillArray(Shareholder  ClientList[], int &numclients );
void PrintArray(Shareholder  ClientList[], int numclients );
void FindCat (Shareholder  ClientList[], int numclients );
void FindAssets(Shareholder  ClientList[], int numclients );
//the main function of the program
int main()
{
      //Initialization and declaration of the Array
      Shareholder  ClientList[maxclients ];
      //variable definitions
      int numclients  = 0;

      cout << fixed << showpoint << setprecision(2);
      //call for the fillArray function which fills the client list
	  fillArray(ClientList, numclients);
      //call the print function that displays the movie list
      cout << "=================================" << endl;
	  PrintArray(ClientList, numclients);

      //call the FindCat function that displays client data by category
      cout << "=============== FindCat ==================" << endl;
	  FindCat(ClientList, numclients);

      //call the FindAssets function to calculate the assest data
      cout << "================ FindAssets =================" << endl;
	  FindAssets(ClientList, numclients);
  
       system("pause");
  return 0;
}
//this function fills the array
void fillArray(Shareholder  ClientList[], int &numclients )
{
	ifstream indata;


	//Now we will open the file
	indata.open("shares.txt");
	if (! indata)
	{
		cerr << "Error" << endl;	
	}
  while(!indata.eof()&& numclients  < maxclients )
  {
	  getline(indata, ClientList[numclients].Name);
	  getline(indata, ClientList[numclients].Category);
	  indata >> ClientList[numclients].Shares;
	  indata.ignore();
	  numclients++;


  }
  indata.close();
}

void FindCat (Shareholder  ClientList[], int numclients )
{

    string mycat;
	int cnt = 0 , sum = 0;

    cout << endl << endl;
    cout << "Enter the category (Gold, Silver or Bronze): ";
	cin >> mycat;


    cout << endl << endl;
    cout << "-----------------------" << endl;
    cout << "The " << mycat << " clients. \n";
    cout << "-----------------------" << endl;
    //???????????? add loop code here ????????????????
	for (int k = 0; k < numclients; k++)
	{
		if (ClientList[k].Category == mycat)
		{
			cout << setw(20) << ClientList[k].Name
				<< setw(15) << ClientList[k].Shares << endl;
			cnt++;
			sum += ClientList[k].Shares;
		}
	}





	cout << "_________________________________________________________________ " << endl;
	cout << "The average " << mycat << " shares: " << sum/cnt << endl;
	cout << "_________________________________________________________________ " << endl;


}
void FindAssets(Shareholder  ClientList[], int numclients)
{   //???????????? add loop code here ????????????????
	double goldval = 8.95, silverval = 4.95, bronzeval = 1.95, goldsum=0, silversum=0, bronzesum=0, totalsum=0;

	for (int i = 0; i < numclients; i++)
	{
		if (ClientList[i].Category == "Gold")
		{
			goldsum += goldval *ClientList[i].Shares;
		}
		if (ClientList[i].Category == "Silver")
		{
			silversum += silverval* ClientList[i].Shares;
		}
		if (ClientList[i].Category == "Bronze")
		{
			bronzesum += bronzeval* ClientList[i].Shares;
		}
		totalsum = goldsum + silversum + bronzesum;
	}






    cout << right << "*******************************************\n";
    cout << "The value of the Gold Shareholders is   $" << setw(10) <<  goldsum << endl;
    cout << "The value of the Silver Shareholders is $" << setw(10) <<  silversum << endl;
    cout << "The value of the Bronze Shareholders is $" << setw(10) <<  bronzesum << endl;
    cout << "The Total value of the shareholeds is   $" << setw(10) <<  totalsum << endl;
}

//this function prints out the movies in the array
void PrintArray(Shareholder  ClientList[], int numclients )
{
    cout << left << setw(5) << "#"  << setw(20) << "Name" << setw(15) 
        << setw(15) << "Category" << setw(15) << "Shares" << endl;
  
    cout << setw(5) << "-"  << setw(20) << "-----" << setw(15) 
        <<  setw(15) << "--------" << setw(15) << "------------" << endl;
     
	for(int i = 0;i < numclients ; i++)
	{
		cout << setw(5) << (i+1) 
			<< setw(20)<< ClientList[i].Name 
			<< setw(15)<< ClientList[i].Category 
			<< setw(15)<< ClientList[i].Shares << endl;
	}
}


