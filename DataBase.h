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
#include "Element.h"
#include "HashedTable.h"

class DataBase
{
private:
	BinarySearchTree<Element*>* DataTree; //pointer to BST
    HashedTable<Element*>* DataHash;      //pointer to Hashed table
    int arraySize;
    int Count;
    
public:
    //reads file, creates all stars in memory dynamically, fills DataTree and DataHash with pointers to stars.
	DataBase();
    ~DataBase(){}; //!!!!!delete
    //(3). Find and display one data record using the primary key
    void Display(string name);
    //(4). List data in hash table sequence
    //(5). List data in key sequence (sorted)
    void List(string order);
    //(2). Delete data
	void Delete(string name);
    //(1). Add new data
    void Add(string name);
    //(6). Print indented tree
    void PrintTree();
    //(7). Hash statistics
    void HashStatistic();
    void Quit();
    
    
	
};



#endif
