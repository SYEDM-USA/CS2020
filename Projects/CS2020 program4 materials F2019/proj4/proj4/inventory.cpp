//Class code 415
#include <iostream>
#include <iomanip>
#include "inventory.h"
using namespace std;

//Constructor
Inventory::Inventory(int oitemNumber, int oquantity, double ocost)
{
	if (oitemNumber < 0)
	{
		oitemNumber = 0;
	}
	if (oquantity < 0)
	{
		oquantity = 0;
	}
	if (ocost < 0)
	{
		ocost = 0;
	}
	itemNumber = oitemNumber;
	quantity = oquantity;
	cost = ocost;
}
// Setter function for item Number
void Inventory::setItemNumber(int oitemNumber)
{
	if (oitemNumber < 0)
	{
		oitemNumber = 0;
	}
	itemNumber = oitemNumber;
}
// Setter function for quantity
void Inventory::setQuantity(int oquantity)
{
	if (oquantity < 0)
	{
		oquantity = 0;
	}
	quantity = oquantity;
}
// Setter function for cost
void Inventory::setCost(double ocost)
{
	if (ocost < 0)
	{
		ocost = 0;
	}
	cost = ocost;
}

// getter function for item Number
int Inventory::getItemNumber()
{
	return itemNumber;
}
// getter function for quantity
int Inventory::getQuantity()
{
	return quantity;
}
// getter function for cost
double Inventory::getCost()
{
	return cost;
}
// Setter function for totalcost
double Inventory::getTotalCost()
{
	return quantity * cost;
}
