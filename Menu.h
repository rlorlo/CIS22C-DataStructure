//
//  menuPropmt.h
//  Team project
//
//  Created by Richard and Tatiana


#ifndef menu_h
#define menu_h


#include"DataBase.h"
#include <string>

class Menu
{
private:

public:
	string OpenFile(DataBase& a, string fileName);
	//(1). Add new data
	void Add(DataBase& a, string name, string name2, int RA_h, int RA_m, float Dec, string SpT, float VisM, float AbsM, int Distance);
	//(2). Delete data
	bool Delete(DataBase&, string name);
	//(3). Find and display one data record using the primary key
	string Display(const DataBase&, string starToDisplay);
	//(4). List data in hash table sequence
	//(5). List data in key sequence (sorted)
	//string List(const DataBase&);
	//(6). Print indented tree
	//string PrintTree(const DataBase&);
	//(7). Hash statistics
	string HashStatistic(const DataBase&);
	//(8). Undo a delete
	bool Undo(DataBase&);
	//(9). Save changes. Clears stack
	void Save(const DataBase&);//, string fileName);
	//(10). Search for data. Returns true if found.
	bool Search(DataBase& d, string name);
	//(11). Quits out of menu.
	void Quit(DataBase& d);
	string FloatToStr(float Num);
	string IntToStr(int Num);



};



#endif
