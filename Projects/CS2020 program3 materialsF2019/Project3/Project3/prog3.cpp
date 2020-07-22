//415 Muhammed Abubaker Syed
// Program 3 October 17
// Purpose:To create a linked lidt with student info


#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Creating a struct of type student
struct Student
{
	string name; 
	int id;
	string status;
	double gpa;
	Student *nextstudent;
};
//Function Definition
void destroyList(Student *&FirstStud);
Student* CreateStudent(string name,int id,string status,double gpa);
void addfrontstudent(Student *&FirstStud,Student *newStudent);
void Removestud(Student*& FirstStud, int iddelete);
void printlist(Student* FirstStud);
void printtype(Student* FirstStud, int text);
void deanslist(Student* FirstStud);

int main()
{
	//assignment statements
	int line;
	Student *FirstStud = nullptr;
	Student *newStudent = nullptr;
	string name, status;
	int id;
	double gpa;

	//reading file
	ifstream infile;
	infile.open("prog3.txt");
	infile >> line;

	//Creating loop to do tasks
	while (line)
	{
		// Option1
		if (line == 1)
		{
			getline(infile, name);
			infile >> id;
			infile.ignore();
			getline(infile, status);
			infile >>gpa;
			infile.ignore();
			newStudent = CreateStudent(name,id,status,gpa);
			addfrontstudent(FirstStud, newStudent);
			infile >> line;
		}
		//option2
		else if (line == 2)
		{
			int iddelete;
			infile.ignore();
			infile >> iddelete;
			Removestud(FirstStud, iddelete);

			infile >> line;
		}
		//option3
		else if (line == 3)
		{
			printlist(FirstStud);

			infile >> line;
		}
		//option4
		else if (line == 4)
		{
			int text;
			infile >> text;
			printtype(FirstStud, text);

			infile >> line;
		}
		//option5
		else if (line == 5)
		{
			deanslist(FirstStud);
			infile >> line;
		}
	}

	
	//destroying list at the end of file
	destroyList(FirstStud);
	cout << "Fin!"<<endl << "Program Terminated." << endl;
	infile.close();
	system("pause");
	return 0;
}


//Function to destroy list
void destroyList(Student *&FirstStud)
{
	Student *holdPtr;
	while (FirstStud)
	{
		holdPtr = FirstStud->nextstudent;
		cout<< FirstStud->name << " has now been removed from list."<<endl;
		cout << endl;
		delete FirstStud;
		FirstStud = holdPtr;
	}
	cout << "The list is now empty !" << endl;
	cout << endl;
}
//Function to create list space
Student *CreateStudent(string name, int id, string status, double gpa)
{
	Student *newStudent = new Student;
	
	newStudent->name = name;
	newStudent->id = id;
	newStudent->status = status;
	newStudent->gpa = gpa;

	newStudent->nextstudent = NULL;

	return newStudent;
}
// function to add new created list to the previous list
void addfrontstudent(Student*& FirstStud, Student* newStudent)
{
	newStudent->nextstudent = FirstStud;
	FirstStud = newStudent;
	cout << newStudent->name << "was added to the list" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << endl;

}
//Function to remove student by ID by passing poiter and the student ID to delete
void Removestud (Student*& FirstStud, int iddelete)
{
	Student *nodePtr = nullptr;
	Student *prevpointer = nullptr;
	if (!FirstStud)
	{
		cout << "The list is empty" << endl;
		cout << endl;
		return;
	}
	if (FirstStud->id == iddelete)
	{
		nodePtr = FirstStud;
		FirstStud = FirstStud->nextstudent;
		cout << nodePtr->name << " was removed from list." << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << endl;
		delete nodePtr;
	}
	else
	{
		nodePtr = FirstStud;
		while (nodePtr != NULL && nodePtr->id != iddelete)
		{
			prevpointer = nodePtr;
			nodePtr = nodePtr->nextstudent;
		}
		if (nodePtr)
		{
			prevpointer->nextstudent = nodePtr->nextstudent;
			cout << nodePtr->name << " was removed from list." << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << endl;
			delete nodePtr;
		}
		else
		{
			cout <<"The student : "<<iddelete<<" was not in the list." << endl;
			cout << endl;
		}
	}
}
//Function to print all the list by passing pointer
void printlist(Student* FirstStud)
{
	Student* tptr = FirstStud;
	if (!tptr)
	{
		cout << "The list is empty" << endl;
		cout << endl;
		return;
	}
	cout<< left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Status" << setw(10)<<"GPA" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	while (tptr)
	{
		cout<<fixed<< setw(20)<< tptr->name<< setw(10) <<tptr->id << setw(10) << tptr->status << setw(10)<< setprecision(2) << tptr->gpa << endl;
		tptr = tptr->nextstudent;
	}
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << endl;
}
//Function to print Deans list students by passing pointer
void deanslist(Student* FirstStud)
{
	int cnt = 0;
	Student* tptr = FirstStud;
	cout << "The Dean's list students are: " << endl;
	cout << left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Status" << setw(10) << "GPA" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;

	while (tptr)
	{
		if (tptr->gpa >= 3.5)
		{
			cout <<fixed<< setw(20) << tptr->name << setw(10) << tptr->id << setw(10) << tptr->status << setw(10) << setprecision(2) << tptr->gpa << endl;
			cnt++;
		}
		tptr = tptr->nextstudent;
	}
	if (cnt == 0)
	{
		cout << "There were no Deans list students on the list." << endl;
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;
}
//Function to print Student of particular status by passing pointer and type 
void printtype(Student* FirstStud, int text)
{
	string type;
	int cnt = 0;
	Student* tptr = FirstStud;
	if (text == 1)
	{
		type = "Fresh";
		cout << "The Freshman are: " << endl;
		cout << left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Status" << setw(10) << "GPA" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

	}
	else if (text == 2)
	{
		type = "Soph";
		cout << "The Sophmores are: " << endl;
		cout << left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Status" << setw(10) << "GPA" << endl;
		cout << "---------------------------------------------------------------------------" << endl;

	}
	else if (text == 3)
	{
		type = "Junr";
		cout << "The Juniors are: " << endl;
		cout << left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Status" << setw(10) << "GPA" << endl;
		cout << "----------------------------------------------------------------------------" << endl;

	}
	else
	{
		type = "Senr";
		cout << "The Seniors are: " << endl;
		cout << left << setw(20) << "Name" << setw(10) << "ID" << setw(10) << "Status" << setw(10) << "GPA" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
	}
	while (tptr)
	{
		if (tptr->status == type)
		{
			cout <<fixed<< setw(20) << tptr->name << setw(10) << tptr->id << setw(10) << tptr->status << setw(10) << setprecision(2) << tptr->gpa << endl;
			cnt++;
		}
		tptr = tptr->nextstudent;
	}
	if (cnt == 0)
	{
		cout << "There were no " << type << " on the list." << endl;
	}
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << endl;
}