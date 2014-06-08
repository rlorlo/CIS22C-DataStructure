//
//  DataBase.h
//  Team project
//
//  Created by Tatiana Karminskaya on 5/22/14.


#ifndef Team_project_DataBase_h
#define Team_project_DataBase_h

#include "BinaryNode.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "pointerToDataRecord.h"
#include "HashedTable.h"
#include "LinkedStack.h"

class DataBase
{
protected:
	BinarySearchTree<pointerToDataRecord>* DataTree; //pointer to BST
    HashedTable* DataHash;      //pointer to Hashed table
	LinkedStack<DataRecord*>* DataStack; // pointer to Stack
    int arraySize;
    int Count;
    
public:
    //reads file, creates all stars in memory dynamically, fills DataTree and DataHash with pointers to stars.
	DataBase();
    ~DataBase(){}; //!!!!!delete
	BinarySearchTree<pointerToDataRecord>* accessTree() const { return DataTree; }
	HashedTable* accessHash() const { return DataHash; }
	LinkedStack<DataRecord*>* accesStack() const { return DataStack; }	
};



#endif
