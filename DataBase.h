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
private:
	BinarySearchTree<pointerToDataRecord>* DataTree;	//pointer to BST
    HashedTable* DataHash;								//pointer to Hashed table
	LinkedStack<DataRecord*>* DataStack;				//pointer to Stack
	int count;
    
public:
	DataBase() : DataStack(0), DataTree(0), count(0), DataHash(0) {};// { DataHash = new HashedTable(50); }
    ~DataBase(){}; //!!!!!delete
	void Allocation() {DataHash = new HashedTable(count); DataTree = new BinarySearchTree<pointerToDataRecord>; }
	BinarySearchTree<pointerToDataRecord>* accessTree() const { return DataTree; }
	HashedTable* accessHash() const { return DataHash; }
	LinkedStack<DataRecord*>* accesStack() const { return DataStack; }
	void incrementCount() {count++;}
	/*void IncArraySize() {arraySize++};
	void DecArraySize() {arraySize--};
	int getArraySize() {return arraySize};*/
};



#endif
