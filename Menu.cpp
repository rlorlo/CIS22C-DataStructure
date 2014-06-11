#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>

//template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); } 
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
		if (x == 0)
			File >> buffer;
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
			n2 = "NoName";
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
	DataRecord* DeleteRecord = new DataRecord;
	DeleteRecord->set_name(name);
	DataRecord* Temp = 0;;//will need this to push on to stack.
	if (d.accessHash()->findEntry(DeleteRecord, Temp))
	{
		d.accesStack()->push(Temp);
		d.accessHash()->remove(Temp);
		pointerToDataRecord Holder(Temp);
		d.accessTree()->remove(Holder);
		return true;
	}
	return false;
}

string Menu::Display(const DataBase& c, string starToDisplay)
{	
	DataRecord* lookingFor= new DataRecord;
	DataRecord* found = 0;
	lookingFor->set_name(starToDisplay);
	//if (c.accessHash()->findEntry(&lookingFor, found))
	pointerToDataRecord look(lookingFor);
	pointerToDataRecord find(found);
	if(c.accessTree()->getEntry(lookingFor, find))
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
/*
string Menu::List(const DataBase& d)
{
	//prompt user to decide which data to list
	cout << "h. for hash sequence\ns. for sorted sequence\n";
	string input;
	cin >> input;
	if (input == "h")
		//print hash
		cout << "print hash";
	else
		//print sorted
		d.inOrder(display);
		cout << "inorder";
}
string Menu::PrintTree(const DataBase& e)
{
	//print indented tree
	//e.printIndentedTree(Display);
	cout << "print indented tree";
}
*/
string Menu::HashStatistic(const DataBase& f)
{
	//print hash statistic
	return "hash statisitics";
}
bool Menu::Undo(DataBase& d)
{
	//add to Hash Table and BST
	DataRecord* Temp = 0;
	DataRecord* topStack = 0;
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
		cout << "undo was successful";
		return true;
	}
}

void Menu::Save(const DataBase& d)//, string fileName)
{
	//save to file output
	//d.accesStack()->clear();
	/*save to file output
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
	File.close();*/
}
