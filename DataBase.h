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
	StackInterface<DataRecord*>* DataStack;				//pointer to Stack
	int count;
    
public:
	DataBase() : DataStack(0), DataTree(0), count(0), DataHash(0) {};// { DataHash = new HashedTable(50); }
    //~DataBase(){}; //don't need since we did no allocation in constructor.
	void Allocation() { DataHash = new HashedTable(count); DataTree = new BinarySearchTree<pointerToDataRecord>; DataStack = new LinkedStack<DataRecord*>; }
	void Deallocation() { delete DataHash; delete DataTree; delete DataStack; }
	BinarySearchTree<pointerToDataRecord>* accessTree() const { return DataTree; }
	HashedTable* accessHash() const { return DataHash; }
	StackInterface<DataRecord*>* accesStack() const { return DataStack; }
	void incrementCount() {count++;}
	void decrementCount() { count--; };
	int getCount() const { return count; };
	/*void IncArraySize() {arraySize++};
	void DecArraySize() {arraySize--};
	int getArraySize() {return arraySize};*/
};



#endif
