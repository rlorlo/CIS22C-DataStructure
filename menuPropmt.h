//
//  menuPropmt.h
//  Team project
//
//  Created by Richard and Tatiana


#ifndef menuPrompt_h
#define menuPrompt_h


#include"DataBase.h"
//#include "DataBase.h"

class Menu
{
private:
	//(1). Add new data
	void Add(DataBase&);
	//(2). Delete data
	void Delete(DataBase&);
	//(3). Find and display one data record using the primary key
	void Display(const DataBase&);
	//(4). List data in hash table sequence
	//(5). List data in key sequence (sorted)
	void List(const DataBase&);
	//(6). Print indented tree
	void PrintTree(const DataBase&);
	//(7). Hash statistics
	void HashStatistic(const DataBase&);
	//(8). Undo a delete
	void Undo(DataBase&);
	//(9). Save changes. Clears stack
	void Save(const DataBase&);
	//Quit function. Asks if you want to save data before quitting.
	void Quit(const DataBase& d);
public:

	Menu();

};



#endif
