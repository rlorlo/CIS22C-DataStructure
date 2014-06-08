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
	/* ***************************************************************
	This will have to move to the head ptr.
	************************************************************** */
	 //pointer to linked stack

public:
	//reads file, creates all stars in memory dynamically, fills DataTree and DataHash with pointers to stars.
	Menu();
	/* ******************************************************************************************************
	Instead of passing in the BinarySearchTree, I would be passing in the DataRecord and the display functions.
	I was just using the BST to try to test my functions.
    *******************************************************************************	*/
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
	//Don't need function quit.



};



#endif
