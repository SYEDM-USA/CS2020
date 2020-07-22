//415 Muhammed Abubaker Syed
// Program 1 September19
// Purpose: Writing a program that reads data from file called insur.txt and displays appropraite information.

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//defined constant
const int maxelements = 50;
//protypes of the other functions 
void fillArray(string clientName[], string policy[], int years[], int premium[], int &numClients);
void PrintArray(string clientName[], string policy[], int years[], int premium[], int numClients);
void BSort(string clientName[], string policy[], int years[], int premium[], int numClients);
void LoyalClient(string clientName[], int years[], int numClients);
void ShowBoats(string clientName[], string policy[], int premium[], int numClients);
int HighestPremium(int premium[], int numClients);
void FindClient(string clientName[], string policy[], int years[], int premium[], int numClients);
int BinarySearch(string clientName[], int numClients, string targetName);


//the main function of the program
int main()
{
	//Initialization and declaration of the Array
	string clientName[maxelements];
	string policy[maxelements];
	int years[maxelements];
	int premium[maxelements];
	//variable definitions
	int numClients = 0;
	int highpremium = 0;
	//call for the fillArray function which fills the lists
	fillArray(clientName, policy, years, premium, numClients);
	//call the print function that displays the lists
	PrintArray(clientName, policy, years, premium, numClients);
	//call the Bsort function that sorts the lists
	BSort(clientName, policy, years, premium,  numClients);
	//call the print function that displays the sorted lists
	PrintArray(clientName, policy, years, premium, numClients);
	//call the LoyalClient function that displays the loyal clients
	LoyalClient(clientName, years, numClients);
	//call the ShowBoats function that displays the clients with boat policy with premium of $4800 or more
	ShowBoats(clientName, policy, premium, numClients);
	//Call the HighestPremium function to return position of the client with the highest premium
	highpremium = HighestPremium(premium, numClients);
	cout << "***********************************************************************" << endl;
	cout << clientName[highpremium] << " has the highest premium of $ " << premium[highpremium] << endl;
	cout << "***********************************************************************" << endl;
	//Call the findclient function to find client. 
	FindClient(clientName, policy, years, premium, numClients);


}

//this function fills the array
void fillArray(string clientName[], string policy[], int years[], int premium[], int& numClients) 
{
	ifstream infile;

	// open the file with verification
	infile.open("insur.txt");


	//input data until the end of file or the array is full
	while (!infile.eof() && numClients < maxelements)
	{
		getline(infile, clientName[numClients]);
		getline(infile, policy[numClients]);
		infile >> years[numClients];
		infile >> premium[numClients];
		infile.ignore();
		numClients++;

	}


	infile.close();

}
// function to print array
void PrintArray(string clientName[], string policy[], int years[], int premium[], int numClients)
{
	cout << "***********************************************************************" << endl;
	cout << left << setw(20) << "Client" << setw(20)
		<< "Policy" << setw(20) << "Years"
		<< setw(20) << "Premium" << endl;

	cout << setw(20) << "------" << setw(20)
		<< "------" << setw(20) << "-----"
		<< setw(20) << "-------" << endl;

	for (int i = 0; i < numClients; i++)
	{
		cout << setw(20) << clientName[i]
			<< setw(20) << policy[i]
			<< setw(20) << years[i]
			<< setw(20) << premium[i] << endl;

	}
	cout << "***********************************************************************" << endl;
}
//function to sort array alphabetically
void BSort(string clientName[], string policy[], int years[], int premium[], int numClients)
{
	string stemp1, stemp2;
	int temp1, temp2;
	bool sort = false;

	while (!sort)
	{
		sort = true;
		for (int k = 0; k < (numClients - 1); k++)
		{
			if (clientName[k] > clientName[k + 1])
			{
				stemp1 = clientName[k];
				clientName[k] = clientName[k + 1];
				clientName[k + 1] = stemp1;

				stemp2 = policy[k];
				policy[k] = policy[k + 1];
				policy[k + 1] = stemp2;

				temp1 = years[k];
				years[k] = years[k + 1];
				years[k + 1] = temp1;

				temp2 = premium[k];
				premium[k] = premium[k + 1];
				premium[k + 1] = temp2;


				sort = false;

			}
		}
		numClients--;
	}
}
//function to print loyal client
void LoyalClient(string clientName[], int years[], int numClients)
{
	cout << "Loyal Client List:" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << left << setw(20) << "Client"
		<< setw(20) << "Years" << endl;
	cout << left << setw(20) << "------"
		<< setw(20) << "-----" << endl;

	for (int i = 0; i < numClients; i++)
	{
		if (years[i] >= 10)
		{
			cout << setw(20) << clientName[i]
				<< setw(20) << years[i] << endl;

		}
	}
	cout << "***********************************************************************" << endl;
}
// function to print showboats
void ShowBoats(string clientName[], string policy[], int premium[], int numClients)
{
	cout << "Show Boat List:" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << left << setw(20) << "Client"
		<< setw(20) << "Premium" << endl;
	cout << left << setw(20) << "------"
		<< setw(20) << "-----" << endl;

	for (int i = 0; i < numClients; i++)
	{
		if (premium[i] >= 4800 && policy[i]=="Boat")
		{
			cout << setw(20) << clientName[i]
				<< setw(20) << premium[i] << endl;

		}
	}
	cout << "***********************************************************************" << endl;
}
//finction to print highest premium
int HighestPremium(int premium[], int numClients)
{
	int highestpremium = 0,pos = 0;
	for (int i = 0; i < numClients; i++)
	{
		if (highestpremium < premium[i])
		{
			highestpremium = premium[i];
			pos = i;
		}
	}
	return pos;
}
//function to print the client info 
void FindClient(string clientName[], string policy[], int years[], int premium[], int numClients)
{
	string targetName;
	int clientpos;
	cout << "Enter the client's name: ";
	getline(cin, targetName);
	clientpos = BinarySearch(clientName, numClients, targetName);
	if (clientpos == -1)
	{
		cout << "Client not found"<<endl;
	}
	else
	{
		cout << "Client: " << clientName[clientpos] << endl;
		cout << "Policy: " << policy[clientpos] << endl;
		cout << "Years: " << years[clientpos] << endl;
		cout << "Premium: " << premium[clientpos] << endl;
	
	}


}
// function to find client
int BinarySearch(string clientName[], int numClients, string targetName)
{
	for (int i = 0; i < numClients; i++)
	{
		if (targetName == clientName[i])
		{
			return i;
		}
	}
	return -1;
}

