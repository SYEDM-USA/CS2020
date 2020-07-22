// This program calculates the number of soccer teams that a 
// youth league may create from the number of available players.  
// Input validation is performed with while loops.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int players, teamPlayers, numTeams, leftOver;
    string move_on;

	cout << "Would you like to run this program Y or N: ";
	cin  >> move_on;
    while(move_on != "Y" && move_on != "y")
    {   cout << "I'll ask again!!" << endl;
	    cout << "Would you like to run this program Y or N: ";
	    cin  >> move_on;
    }


	// Get the number of players per team.
	cout << "How many players do you wish per team?\n";
	cout << "(Enter a value in the range 9 - 15): ";
	cin  >> teamPlayers;
	while (teamPlayers < 9 || teamPlayers > 15)   // Validate input
	{
		cout << "Team size should be 9 to 15 players.\n";
		cout << "How many players do you wish per team? ";
		cin  >> teamPlayers;
	}
	// Get the number of players available.
	cout << "How many players are available? ";
	cin  >> players;
	while (players < 0)                           // Validate input.
	{
		cout << "Please enter a positive number: ";
		cin  >> players;
	}
	// Perform calculations.
	numTeams = players / teamPlayers;	
	leftOver = players % teamPlayers;
	cout << "There will be " << numTeams << " teams with ";
	cout << leftOver << " players left over.\n";
	return 0;
}
