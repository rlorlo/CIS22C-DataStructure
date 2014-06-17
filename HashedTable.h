//
//  HashedArray.h
//  Lab3
//
//  Created by Tom Rico on 5/3/14.
//  Copyright (c) 2014 Tom Rico. All rights reserved.
//

#ifndef Lab3_HashedArray_h
#define Lab3_HashedArray_h

#include "DataRecord.h"
#include "HashedNode.h"
#include <string>
#include <iostream>


class DataRecord;

class HashedTable
{
protected:
    HashedNode<DataRecord*>* ArrPtr;
    int GetNum();
    int ArrSize;
    int count;
	int ColCount;
    int primeArray[10];

    
    
public:
	HashedTable(int numNodes=0);
    ~HashedTable() {delete ArrPtr;}
    void displayStats();
    int hash(const DataRecord* nodePtr);
    int hash(const string nodePtr);
    int ColRes(int index, int count);
    bool findEntry(const string targetKey, DataRecord*& target);
    bool findEntry(const DataRecord* targetKey, DataRecord*& target);
    void insert(DataRecord* star);
    bool remove(const DataRecord* star);
    void clearArray();
    string printHashSequence(const string key);
	void printOutToFile(ostream& o);
    string printHash();

};


#endif
