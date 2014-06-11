//
//  UserInterface.h
//  Team project
//
//  Created by Tatiana Karminskaya on 6/3/14.
//  Copyright (c) 2014 t. All rights reserved.
//

#ifndef __Team_project__UserInterface__
#define __Team_project__UserInterface__

#include <iostream>
#include <fstream>
#include <cstring>
#include "menu.h"
#include "DataBase.h"

using namespace std;

class UserInterface
{
    
private:
	Menu myFunc;
	string name, name2, SpT;
	int RA_h, RA_m;
	float Dec, VisM, AbsM;
	int Distance;
	int openFCount;
	DataBase myDB;
	//string fileName;// I want to add this, so we know which file the user will be writing back into when he saves
public:
	UserInterface() : openFCount(0) {};
	char Choice[2];
    char Choice2[2];
	void PrintMenu();
    void ChoiceFunc();
};



void UserInterface :: PrintMenu()
{
    cout << "Main menu" << endl;
	cout << "o. open file" << endl;
    cout << "a. add" << endl;
    cout << "l. list" << endl;
    cout << "d. delete" << endl;
	cout << "D. display" << endl;
    cout << "u. undo" << endl; // change to choice u
    cout << "p. print tree" << endl;
    cout << "h. show hashed statistic" << endl; // changed to choice h
    cout << "q. quit contacts" << endl;
    cout << "Choice: ";
}

void UserInterface::ChoiceFunc()
{
	string fileName;
	string cmp = " ";
	if (strcmp(Choice, "o") == 0)
	{
		if (openFCount > 0)
		{
			cout << "Would you like to save previous file? (y/n) \n";
			char answer[2];
			cin >> answer;
			if (strcmp(answer, "y") == 0)
			{
				myFunc.Save(myDB);

			}

		}
		while (cmp != "File opened successfully \n")
		{
			cout << "Enter filename: ";
			cin >> fileName;
			cout << myFunc.OpenFile(myDB, fileName);
			cmp = myFunc.OpenFile(myDB, fileName);
		}
		openFCount++;
	}



	else if ((openFCount > 0) && (strcmp(Choice, "a")) == 0)
	{
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, name);

		if (!myFunc.Search(myDB, name)) //new addition
		{

		}


		else if ((openFCount > 0) && (strcmp(Choice, "a") == 0))
		{
			cout << "Enter new name: ";
			cin.clear();
			cin.ignore();
			getline(cin, name);
			cout << name << endl;

			if (!myFunc.Search(myDB, name)) //new addition
			{

				cout << "Enter Greek name: ";
				cin.clear();
				cin.ignore();
				getline(cin, name2);
				cout << name2 << endl;

				cout << "Enter equatorial coordinates: ";
				cout << "Right ascension, hours: ";

				while (!(cin >> RA_h) || RA_h < 0)
				{
					cout << "Right ascension, hours: ";
					cin.clear();
					cin.ignore(256, '\n');
				}

				cin.clear();
				cin.ignore(256, '\n');
				cout << "Right ascension, minutes: ";
				while (!(cin >> RA_m) || RA_m < 0)
				{
					cout << "Right ascension, minutes: ";
					cin.clear();
					cin.ignore(256, '\n');
				}

				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter Declination: ";

				while (!(cin >> Dec))
				{
					cout << "Enter Declination:  ";
					cin.clear();
					cin.ignore(256, '\n');
				}

				cin.clear();
				cin.ignore(256, '\n');



				cout << "Enter spectral type: ";
				cin >> SpT;
				getline(cin, SpT);

				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter Visual magnitude: ";

				while (!(cin >> VisM))
				{
					cout << "Enter Visual magnitude:  ";
					cin.clear();
					cin.ignore(256, '\n');
				}

				cin.clear();
				cin.ignore(256, '\n');

				while (!(cin >> AbsM))
				{
					cout << "Enter Absolute magnitude:  ";
					cin.clear();
					cin.ignore(256, '\n');
				}

				cin.clear();
				cin.ignore(256, '\n');

				while (!(cin >> Distance) || Distance < 0)
				{
					cout << "Enter Distance:  ";
					cin.clear();
					cin.ignore(256, '\n');
				}
				cin.clear();
				cin.ignore(256, '\n');

				myFunc.Add(myDB, name, name2, RA_h, RA_m, Dec, SpT, VisM, AbsM, Distance);//moved out of while loop
				cout << "Add Successful\n"; // new addition

			}

			else //new addition
			{
				cout << "Data already in the table\n"; // new addition
			}

		}
	}

		//add
		else if (strcmp(Choice, "d") == 0)
		{
			cout << "Enter name for deletion: ";
			cin >> name;
			if (myFunc.Delete(myDB, name))
			{
				cout << "Delete Successful\n";
			}
			cout << "Data doesn't exists.";
		}

		//stop add

		/*
		else if(strcmp(Choice, "l") == 0)
		{
		cout << "h. List data in hash table sequence" << endl;
		cout << "s. List data in key sequence (sorted)" << endl;
		Choice2[0] = 'y';
		while(strcmp(Choice2, "h") !=0 && strcmp(Choice2, "s") != 0)
		{
		cout << "Choice: ";
		cin >> Choice2;
		cout << myFunc.List(myDB);
		cout << endl;
		}
		}

		else if(strcmp(Choice, "p") == 0)
		{
		cout << myFunc.PrintTree(myDB);
		cout << endl;
		}*/


		else if (strcmp(Choice, "D") == 0)
		{
			cout << "Enter star name to disply: ";
			cin.ignore();
			getline(cin, name);

			cout << myFunc.Display(myDB, name) << endl;

		}


		else  if (strcmp(Choice, "h") == 0)
		{
			cout << myFunc.HashStatistic(myDB);
		}
		//added
		else if (strcmp(Choice, "u") == 0)
		{
			if (myDB.accesStack()->isEmpty())
				cout << "Nothing to Undo";
			else if (myFunc.Undo(myDB))
				cout << "Undo Successful";
			else
				cout << "Data already exists in the table";
		}

		else if (strcmp(Choice, "s") == 0)
		{
			myFunc.Save(myDB);
			//want to add
			//myFunc.Save(myDB, fileName);
			//cout << "Data file was overwritten and saved" << endl;
		}
		//end add
		else if (strcmp(Choice, "q") == 0)
		{
			/*want to add
			cout << "Do you want to save your data? y/n\n";
			Choice2[0] = 'a';
			while (strcmp(Choice2, "y") != 0 && strcmp(Choice2, "n") != 0)
			{
			cout << "Choice: ";
			cin >> Choice2;
			cout << endl;
			}
			if (strcmp(Choice2, "y") == 0)
			{
			myFunc.Save(myDB, fileName);
			cout << "Data file was overwritten and saved" << endl;
			}
			}*/
			myFunc.Save(myDB);
			cout << "Data file was overwritten and saved" << endl;
		}
		else
		{
			cout << "not valid Choice" << endl;
			cout << endl;
		}

	}



#endif /* defined(__Team_project__UserInterface__) */
