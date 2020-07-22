#include<iomanip>
#include<iostream>

using namespace std;

// D10 = 65;
//D20 =100
//d21 = 36;
int DP1 = 97, DP2 = 77, d10=13.64, d20 = 13.64,d21 =34.13;

int A, E, F, Po, P0, H, I, dpk, Dpk, alpha, X, Y;
int main()
{
	A = (acos(((pow(d21, 2)) + (pow(d20, 2)) - (pow(d10, 2))) / (2 * d21 * d20))) * 57.2957795;
	E = (acos(((pow(d21, 2)) + (pow(DP2, 2)) - (pow(DP1, 2))) / (2 * d21 * DP2))) * 57.2957795;
	F = (acos((pow(DP1, 2) + pow(DP2, 2) - pow(d21, 2)) / (2 * DP1 * DP2))) * 57.2957795;
	Po = (sqrt(abs((2 * d20 * DP2 * cos(E - A)) - pow(d20, 2) - pow(DP2, 2))));
	P0 = (sqrt(abs(pow(d20, 2) + pow(DP2, 2) - (2 * d20 * DP2 * cos(E - A)))));
	H = (acos((pow(P0, 2) + pow(DP2, 2) - pow(d20, 2)) / (2 * P0 * DP2))) * 57.2957795;
	I = (acos((pow(P0, 2) + pow(d20, 2) - pow(DP2, 2)) / (2 * P0 * d20))) * 57.2957795;
	dpk = (sqrt(abs(2 * P0 * d20 * cos(I) - pow(P0, 2) - pow(d20, 2))));
	Dpk = sqrt(abs(pow(P0, 2) + pow(d20, 2) - (2 * P0 * d20 * cos(I))));
	alpha = abs(((acos((pow(DP1, 2) + pow(Dpk, 2) - pow(d21, 2)) / (2 * DP1 * Dpk))) * 57.2957795) - F);
	X = abs(P0 * sin(alpha + H));
	Y = abs(P0 * cos(alpha + H));

	cout << X;
	cout << Y;
	system("pause");

}