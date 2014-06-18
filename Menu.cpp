#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>

string globalString;

template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); } 
string Menu::FloatToStr(float Num)
{
	ostringstream ss;
	ss << Num;
	return ss.str();
}

string Menu::IntToStr(int Num)
{
	ostringstream ss;
	ss << Num;
	return ss.str();
}

string Menu::OpenFile(DataBase& d, string fileName)
{
	//File Data members
	ifstream File;
    //string fileName = "brightstars.txt";
    
    //Data members for DataRecord.h
    string n;       // Name of the star in constellation
    string n2;      // Usual name of the star
    float V;        // Visual magnitude
    float A;        // Absolute magnitude
    int D;          // Distance, in light years
    string S;       // Spectral type (will be converted to color below)
    float De;       // Equatorial coordinate, Declination, in degrees
    int RA_h;
    int RA_m;
//    float Ra;      // Equatorial coordinate, Right ascension, in degrees
    
    // Data members to parse the file
    string buffer;
    char buf[3];
    	
    //Open the file
    File.open(fileName);
	if (!File) return "Can't open file, please try again\n";
	
	while(!File.eof())
	{
        getline(File,buffer);
		d.incrementCount();
    }
    // Here one has to change HashedTable array size according to counted number of lines in file 
	// This is probably where DB is created.
	d.Allocation();
	//d.accessTree()-> new BinarySearchTree<pointerToDataRecord>;

    //File.clear();
	//File.seekg(0);//This will set pointer back to beginning.
    File.close();
    File.open(fileName);
   
	int x = 0;
	//Read data from the file
    while(!File.eof())
	{
		//if (x == 0)
			//File >> buffer;
		File >> buffer;
		File >> n;
		File >> buffer;
		n = n+ " " + buffer;
		File.get(buf, sizeof(buf));
    
		if(buf[1]!=32)
		{
			File >>buffer;
			n = n + buf + buffer;
		}
		File >> buffer;
       
	    if(isdigit(buffer[0]))
		{
			n2 = "";
		}
		else
		{
			n2 = buffer;
			File.get(buf, sizeof(buf));
        
			if(buf[1]!=32)
			{
				File >> buffer;
				n2 = n2 + buf + buffer;
			}
			File >> buffer;
		}
    
		RA_h = stoi(buffer);
		File >> buffer;
		RA_m = stoi(buffer);
    
		//Convert RA to decimal degrees
		//Ra = RA_h / 15.0 +RA.m / 4.0;
    
		File >> buffer;
		De = stof(buffer);

		File >> buffer;
		S = buffer;
		File >> buffer;
		V = stof(buffer);
		File >> buffer;
		A = stof(buffer);
		File >> buffer;
		D = stoi(buffer);
    
		DataRecord* tempStar = new DataRecord();
		
		tempStar->set_name(n);
		tempStar->set_name2(n2);
		tempStar->set_VisM(V);
		tempStar->set_AbsM(A);
		tempStar->set_Distance(D);
		tempStar->set_SpT(S);
		tempStar->set_Dec(De);
        tempStar->set_RAs_h(RA_h);
        tempStar->set_RAs_m(RA_m);
        
		pointerToDataRecord tempHolder(tempStar);
		//insert pointers into BST and Hash Table
		d.accessTree()->insert(tempHolder);
		d.accessHash()->insert(tempStar);
		x++;
    }
    
    // Close the file
	File.close();
	return "File opened successfully \n";
}

bool Menu::Search(DataBase& d, string name)
{
	DataRecord* Search = new DataRecord;
	DataRecord* Holder = 0;;
	Search->set_name(name);
	if (d.accessHash()->findEntry(Search, Holder))
	{
		return true;
	}
	return false;
}

void Menu::Add(DataBase& d, string name, string name2, int RA_h, int RA_m, float Dec, string SpT, float VisM, float AbsM, int Distance)
{
	DataRecord* NewRecord = new DataRecord;
	NewRecord->set_name(name);
	NewRecord->set_name2(name2);
	//NewRecord.set You have RAs blocked in datarecord. Are we keeping it?
	NewRecord->set_VisM(VisM);
	NewRecord->set_AbsM(AbsM);
	NewRecord->set_Distance(Distance);
	NewRecord->set_SpT(SpT);
	pointerToDataRecord Holder(NewRecord);
	d.accessTree()->insert(Holder);
	d.accessHash()->insert(NewRecord);
}

bool Menu::Delete(DataBase& d, string name) //need to pass bool
{
	//DataRecord* DeleteRecord = new DataRecord;
	//DeleteRecord->set_name(name);
	DataRecord* Temp = new DataRecord;//will need this to push on to stack.
	if (d.accessHash()->findEntry(name, Temp))
	{
		d.accesStack()->push(Temp);
		d.accessHash()->remove(Temp);
		pointerToDataRecord Holder(Temp);
		d.accessTree()->remove(Holder);
		return true;
	}
	return false;
}

string Menu::Display(const DataBase& d, string starToDisplay)
{	
	DataRecord* found = new DataRecord;
	if(d.accessHash()->findEntry(starToDisplay, found))
	{
		return "Name of the star in constellation: " + found->get_name() + 
			"\nUsual name of the star: " + found->get_name2() +
			"\nVisual magnitude: " + FloatToStr(found->get_VisM()) +
			"\nAbsolute magnitude: " + FloatToStr(found->get_AbsM()) +
			"\nDistance, in light years: " + IntToStr(found->get_Distance()) +
			"\nSpectral type: " + found->get_SpT() +
			"\nEquatorial coordinate, Declination, in degrees: " + FloatToStr(found->get_Dec()) +
			"\nEquatorial coordinate, Right ascension, in hours" + IntToStr(found->get_RAs_h()) +
			"\nEquatorial coordinate, Right ascension, in mins: " + IntToStr(found->get_RAs_m());
	}
	else return "Star is not found\n";
}

void displayList(pointerToDataRecord & p)
{
	globalString = globalString + p.get_pointer()->get_name() + "("
		+ tostr(p.get_pointer()->get_Distance()) + ")\n";
}

string Menu::List(const DataBase& d, string choice)
{
	//prompt user to decide which data to list
	globalString = "";
	if (d.accessTree()->isEmpty())
		return "No stars in DataBase\n";
	else
	{
		if (choice == "b")
		{
			d.accessTree()->inOrder(displayList);
			return globalString;
		}
		else if (choice == "h")
		{
			return d.accessHash()->printHash();
			return "hash";
		}
		else return "wrong choice\n";
	}
}


void displayTree(pointerToDataRecord p, int level)
// void displayTree(pointerToDataRecord & p, int level)
{
	string tempStr = "";
	string tempName = p.get_pointer()->get_name();
	if (level>0)
	{
		for (int i = 0; i<level; i++)
		{
			tempStr = tempStr + "\t  ";
		}
	}
	tempStr = tempStr + tempName;
	globalString = globalString + tempStr + "\n";
}

string Menu::PrintTree(const DataBase& d)
{
	globalString = "";
	int level = 0;
	d.accessTree()->printIndentedTree(d.accessTree()->getRootPtr(), level, displayTree);
	return globalString;
}

string Menu::HashStatistic(const DataBase& f)
{
	f.accessHash()->displayStats();
	//print hash statistic
	return "hash statisitics";
}
bool Menu::Undo(DataBase& d)
{
	//add to Hash Table and BST
	DataRecord* Temp = new DataRecord;
	DataRecord* topStack = new DataRecord;
	d.accesStack()->peek(topStack);
	d.accesStack()->pop();
	if (d.accessHash()->findEntry(topStack, Temp))
	{
		//data already exists
		return false;
	}
	else
	{
		d.accessHash()->insert(topStack);
		pointerToDataRecord Holder(topStack);
		d.accessTree()->insert(Holder);
		//successful
		//cout << "undo was successful";
		return true;
	}
}

void Menu::Save(const DataBase& d)//, string fileName)
{
	//clears undo
	d.accesStack()->clear();
	//save to file output
	ofstream File;
	string fileName = "tester.txt";
	File.open(fileName);
	while (!File)
	{
		cout << "Error opening file\nEnter filename: ";
		cin >> fileName;
		File.open(fileName);
	}
	d.accessHash()->printOutToFile(File);
	//d.accessTree()->inOrder(filePrint); // this needs to be hash table instead of tree.
	File.close();
}
