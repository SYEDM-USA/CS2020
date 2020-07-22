// Patient Fees
#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
int getSurgeryType();

int main()
{
   int surgeryType;           // To hold the type of surgery

   cout << "\n\nPatient Release Menu\n\n";
   // Get the surgery and medication types.
   surgeryType = getSurgeryType();

   while(surgeryType != 5)
   {    if(surgeryType == 1)
            cout << "\nPatient Tonsillectomy Surgery:  $100" << endl;
       else if(surgeryType == 2)
           cout << "\nPatient Foot Surgery:  $200" << endl;
       else if(surgeryType == 3)
           cout << "\nPatient Knee Surgery:  $300" << endl;
       else if(surgeryType == 4)
           cout << "\nPatient Shoulder Surgery:  $400" << endl;
       surgeryType = getSurgeryType();
   }

   return 0;
}

//***********************************************
// Function getSurgeryType                      *
// Displays a menu of surgery types and gets    *
// a selection from the user. The selection     *
// is returned.                                 *
//***********************************************

int getSurgeryType()
{
   int choice;

   // Display the surgery menu
   cout << "\nTypes of Surgery We Perform\n";
   cout << "---------------------------\n";
   cout << "1 - Tonsillectomy\n";
   cout << "2 - Foot\n";
   cout << "3 - Knee\n";
   cout << "4 - Shoulder\n";
   cout << "5 - Quit\n\n";
   cout << "Choose a type of Surgery (1-5):  ";
   cin  >> choice;
   while (choice < 1 || choice > 5)
   {  
      cout << "Legal values are 1-5.  Please re-enter surgery type: ";
      cin  >> choice;
   }

   return choice;
}
