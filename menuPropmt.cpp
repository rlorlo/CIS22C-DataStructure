//
//  menuPropmt.cpp
//  Team project
//
//  Created by Richard and Tatiana

#include "menuPropmt.h"
#include <iostream>
#include <fstream>

void display(pointerToDataRecord &objPtr)
{
	cout << *(objPtr.get_pointer()) << endl;
}

void filePrint(DataRecord & star, ofstream File)
{
	File << left << setw(23) << star.get_name() << setw(23) << star.get_name2() << setw(10) << star.get_VisM() << setw(10) << star.get_AbsM() << setw(10) << star.get_SpT() << setw(10) << star.get_Distance() << endl;
}

Menu::Menu()
{
	// contains propmt for user to use the menu.
}

void Menu::Add(DataBase& d)
{
	DataRecord* NewRecord = new DataRecord;
	cout << "Enter Star Name:\n";
	string name;
	cin >> name;
	NewRecord->set_name(name); 
	DataRecord* Temp = 0; //Data Temp needed to access getEntry function of Hash.
	if (d.accessHash()->findEntry(NewRecord, Temp))
	{
		cout << "already exists\n";
		return;
	}
	
	string name2;
	string stringVisM;
	string stringAbsM;
	string stringDistance;
	string SpT;

	float VisM;
	float AbsM;
	int Distance;
	
	cout << "Enter Common Name:\n";
	getline(cin, name2, '\n');
	NewRecord->set_name2(name2);
	cout << "Enter Visual magnitude:\n";
	getline(cin, stringVisM, '\n');
	VisM = stof(stringVisM);
	NewRecord->set_VisM(VisM);
	cout << "Enter Absolute magnitude:\n";
	getline(cin, stringAbsM, '\n');
	AbsM = stof(stringAbsM);
	NewRecord->set_AbsM(AbsM);
	cout << "Enter Distance, in light years:";
	getline(cin, stringDistance, '\n');
	Distance = atoi(stringDistance.c_str());
	NewRecord->set_Distance(Distance);
	cout << "Enter Spectral type:";
	getline(cin, SpT, '\n');
	NewRecord->set_SpT(SpT);
	//float set_Dec(); Do we ask for this or calculate for them?
	//float set_RAs();  Do we ask for this or calculate for them?
	pointerToDataRecord Holder(NewRecord);
	d.accessTree()->insert(Holder);
	d.accessHash()->insert(NewRecord);
	}

void Menu::Delete(DataBase& d)
{
	//Asks user for which record to delete.
	DataRecord* DeleteRecord; //We dont need to allocate memory since it is temporary holder.
	string name;
	cout << "Enter Star Name to Delete";
	cin >> name;
	DeleteRecord->set_name(name);
	DataRecord* Temp = 0;;//will need this to push on to stack.
	if (d.accessHash()->findEntry(DeleteRecord, Temp))
	{
		d.accesStack()->push(Temp);
		d.accessHash()->remove(Temp);
		pointerToDataRecord Holder(Temp);
		d.accessTree()->remove(Holder);
		return;
	}
	//can't be found
	cout << "cant be found\n";
	return;

}

void Menu::Display(const DataBase& d)
{	
	//Asks user for which Record they are looking for
	string name;
	cout << "Enter Star Name: ";
	cin >> name;
	DataRecord* LookingFor;//We dont need to allocate memory since it is temporary holder.
	LookingFor->set_name(name);
	DataRecord* Found = 0;
	if (d.accessHash()->findEntry(LookingFor, Found))
	{
		//print what is found.
		cout << *Found;
		return;
	}
	else
	{
		//print cant be found.
		cout << "Cant be found";
		return;
	}
}
void Menu::List(const DataBase& d)
{
	//prompt user to decide which data to list
	string input;
	cout << "h. for hash sequence\ns. for sorted sequence\n";
	cin >> input;
	while (input != "h" && input != "s");
	{
		cout << "Not a valid coice. Please try again.\n";
		cout << "h. for hash sequence\ns. for sorted sequence\n";
		cin >> input;
	} 
	if (input == "h")
		d.accessHash()->printHash(); //Tom, we need a function that will print the data in hash order.
	else
		//print sorted
		d.accessTree()->inOrder(display);
}
void Menu::PrintTree(const DataBase& d)
{
	//print indented tree
//TR	d.accessTree()->printIndentedTree(Display); //Need display function for printIndentedTree
	cout << "print indented tree";
}
void Menu::HashStatistic(const DataBase& d)
{
	d.accessHash()->displayStats();
}
void Menu::Undo(DataBase& d)
{
	if (d.accesStack()->isEmpty())
	{
		cout << "Nothing to Undo";
		return;
	}
	else
	{
		//add to Hash Table and BST
		DataRecord* Temp = 0;
		DataRecord* topStack = 0;
		d.accesStack()->peek(topStack);
		d.accesStack()->pop();
		if (d.accessHash()->findEntry(topStack, Temp))
		{
			//data already exists
			cout << "Data Already Exists";
			return;
		}
		else
		{
			d.accessHash()->insert(topStack);
			pointerToDataRecord Holder(topStack);
			d.accessTree()->insert(Holder);
			//successful
			cout << "undo was successful";
			return;
		}
	}
}
void Menu::Save(const DataBase& d)
{
	d.accesStack()->clear();
	//save to file output
	ofstream File;
	string fileName = "brightstars.txt";
	File.open(fileName);
	while (!File)
	{
		cout << "Error opening file\nEnter filename: ";
		cin >> fileName;
		File.open(fileName);
	}
	//d.accessTree()->inOrder(filePrint); // this needs to be hash table instead of tree.
	File.close();
}

void Menu::Quit(const DataBase& d)
{
	char choice;
	cout << "Do you want to save your data? y/n\n";
	cin >> choice;
	while (choice != 'y' && choice != 'n')
	{
		cout << "invalid choice.\n";
		cout << "Do you want to save your data? y/n\n";
		cin >> choice;
	}
	if (choice == 'y')
		Save(d);
}
