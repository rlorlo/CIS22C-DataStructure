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
    //int primeArray[10];={73,107,127,179,233,283,337,379,419,457};
    int primeArray[10];//={5,20,50,125,300,650,900,1000,1250,1500};

    
    
public:
    HashedTable(int count =0);
    ~HashedTable() {delete ArrPtr;}
    void displayStats();
    int hash(const DataRecord* nodePtr);
    int hash(const string nodePtr);
    int ColRes(int index, int count);
    bool findEntry(const string targetKey, DataRecord* target);
    bool findEntry(const DataRecord* targetKey, DataRecord* target);
    void insert(DataRecord* star);
    void remove(const DataRecord* star);
    void clearArray(HashedNode<DataRecord*>* ArrPtr);
    string printHashSequence(const string key);
    void printHash();

};


#endif
