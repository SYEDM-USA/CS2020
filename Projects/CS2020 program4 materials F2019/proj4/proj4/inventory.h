// Class code 415 Muhammed Abubaker
// Designing an Inventory Class that 
// can hold information and calculate 
// data for items in a retail store's inventory.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Inventory
{
private:
	int itemNumber;
	int quantity;
	double cost;
public:
	Inventory (int oitemNumber= 0, int oquantity= 0, double ocost= 0.0);
	
	void setItemNumber(int itemNumber);
	void setQuantity(int oquantity);
	void setCost(double ocost);

	int getItemNumber();
	int getQuantity();
	double getCost();
	double getTotalCost();


};
