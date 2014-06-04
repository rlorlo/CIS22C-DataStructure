//
//  menuPropmt.h
//  Team project
//
//  Created by Richard and Tatiana


#ifndef menuPrompt_h
#define menuPrompt_h


#include "LinkedStack.h"
#include "TempDataRecord.h"
#include "BinarySearchTree.h"
//#include "DataBase.h"

class Menu
{
private:
	/* ***************************************************************
	This will have to move to the head ptr.
	************************************************************** */
	LinkedStack<DataRecord> DataStack; //pointer to linked stack

public:
	//reads file, creates all stars in memory dynamically, fills DataTree and DataHash with pointers to stars.
	Menu();
	/* ******************************************************************************************************
	Instead of passing in the BinarySearchTree, I would be passing in the DataRecord and the display functions.
	I was just using the BST to try to test my functions.
    *******************************************************************************	*/
	//(1). Add new data
	void Add(BinarySearchTree<DataRecord>&);
	//(2). Delete data
	void Delete(BinarySearchTree<DataRecord>&);
	//(3). Find and display one data record using the primary key
	void Display(const BinarySearchTree<DataRecord>&);
	//(4). List data in hash table sequence
	//(5). List data in key sequence (sorted)
	void List(const BinarySearchTree<DataRecord>&);
	//(6). Print indented tree
	void PrintTree(const BinarySearchTree<DataRecord>&);
	//(7). Hash statistics
	void HashStatistic(const BinarySearchTree<DataRecord>&);
	//(8). Undo a delete
	void Undo(BinarySearchTree<DataRecord>&);
	//(9). Save changes. Clears stack
	void Save(const BinarySearchTree<DataRecord>&);
	//Don't need function quit.



};



#endif
