//
//  File.cpp
//  Lab3
//
//  Created by Tom Rico on 5/1/14.
//  Copyright (c) 2014 Tom Rico. All rights reserved.
//

#include "HashedTable.h"
#include "DataRecord.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>


class DataRecord;

HashedTable::HashedTable(int numNodes) {
	int tempArray[10] = {71,173,281,409,541,659,809,941,1069,1151};
	for(int i =0;i<10;i++)
		primeArray[i] = tempArray[i];
    count=numNodes;
    ArrSize=GetNum();
    ArrPtr = new HashedNode<DataRecord*>[ArrSize];
    cout<<"Array Size: "<<ArrSize<<endl;
    ColCount=0;
    
}


int HashedTable::hash(const DataRecord* A){
    int index=0;
    double index2=0;
    char word[100];

	//string test = A->get_name().c_str();
<<<<<<< HEAD
	strcpy(word, A->get_name().c_str());//forced to changed to _s to use it in vs2013
=======
	strcpy_s(word, A->get_name().c_str());//forced to changed to _s to use it in vs2013
>>>>>>> FETCH_HEAD
    
    for (int i=0; i<3; i++){
        index2=index2+(word[i]*(word[0])*(i+13));
    }
    
    index=((static_cast<int>(index2))%ArrSize);
    
    return index;
}

int HashedTable::hash(const string target){
    int index=0;
    double index2=0;
    char word[40];
    
    strcpy(word,(target.c_str()));
    
    for (int i=0; i<3; i++){
        index2=index2+(word[i]*(word[0])*(i+13));
    }
    
    index=((static_cast<int>(index2))%ArrSize);
    
    return index;
}
//Change to string return
string HashedTable::printHash() {
	//string returnStr;
	stringstream temp;

    for (int i=0; i<ArrSize; i++){
        //temp = "Index " //i<<": "; Need to convert int to string. Have function in menu.cpp already created.
  //TR CHANGED THIS FOR TESTING   
        if(ArrPtr[i].getItem()!=0)
            temp << (ArrPtr[i].getItem())->get_name() << (ArrPtr[i].getColResCount()) << "\n";
        else
            temp << "---\n";
    }
	return temp.str();
}

/*
void HashedTable::printHash() {

    for (int i=0; i<ArrSize; i++){
        cout<<"Index "<<i<<": ";
     
        if(ArrPtr[i].getItem()!=0)
            cout<<(ArrPtr[i].getItem())->get_name()<<endl;
        else
            cout<<"blank\n";
    }
        
}*/


string HashedTable::printHashSequence(const string key){
    int index=-1, ColResCounter=0;
    stringstream hashSequence;
    
    hashSequence<<"Hash Sequence: ";
    index=hash(key);
    
    if(ArrPtr[index].getStatus()!=0)
        while((ColResCounter<ArrSize) && (ArrPtr[index].getStatus() != 0) && ArrPtr[index].getItem()!=0){
            if( (ArrPtr[index].getItem())->get_name() == key)
            {
                hashSequence<<index<<endl;
                return hashSequence.str();
            }
            else {
                hashSequence<<index<<", ";
                ColResCounter++;
                index=ColRes(index, ColResCounter);
            }
        }
        
        return "Item not in list\n"; 
}


void HashedTable::displayStats() {
  cout<< "Total number of collisions: "<< ColCount<<endl;
	/*  int max=0,
        cols=0,
        noCol=0,
        empty=0;
    
    cout << "There are "<<count<<" stars in the list.\n";
    cout<<"The size of the star library is "<<ArrSize<<".\n";
    cout<<"Load factor is "<< (count*100)/ArrSize<<"%"<<endl<<endl;
    
    cout << "Collisions: \n\n";
    
    for (int j=0; j<ArrSize; j++){
        
        //if Element is empty, increment empty
        if (ArrPtr[j].getStatus() == 0) { empty++; }

        //if Element has only one node, increment No Colisions
        if (ArrPtr[j].getStatus() == 1) { noCol++; }
        
        //if Element has more than one node, increment Colisions
        if (ArrPtr[j].getStatus() > 1) {
            cout<<"Index:\t"<<j<<"  \tProbes:\t"<<ArrPtr[j].getStatus()<<endl;
            cols++;
        }
        //look for element with maximum colisions
        if (ArrPtr[j].getStatus() > max) { max=ArrPtr[j].getStatus(); }
    }
    
    cout<<"\nMax number of probes is "<<max<<" at:\n";
    //for all lists with max colisions, display list
    for (int k=0; k<ArrSize; k++){
        if (ArrPtr[k].getStatus()==max){
            cout<<"Index "<<k<<": "; ArrPtr[k].display();
        }
    }

 
        cout<<"No Collisions: "<<noCol<<endl;
//Here are other fun numbers for evaluating hashing:
        cout<<"Collisions: "<<cols<<endl;
        cout<<"Empty Elements: "<<empty<<endl;
        cout<<"Number of elements in lists: "<<count-noCol-cols;
        cout<<endl<<endl;
    */
}

int HashedTable::GetNum() {
    int i=0;
    
    for (int i=0; i<10; i++){
        if (count<(primeArray[i]/2))
            return primeArray[i];
    }
    
    return primeArray[i];
}


bool HashedTable::findEntry(const string targetKey, DataRecord*& target){
    
    int index= hash(targetKey);
    int ColResCounter=0;
    
    
    while((ColResCounter<ArrSize) && (ArrPtr[index].getStatus() != 0) && ArrPtr[index].getItem()!=0){
        if( (ArrPtr[index].getItem())->get_name() == targetKey)
    {
        //cout<<targetKey<<" found at "<<index<<endl;
        target=ArrPtr[index].getItem();
        return true;
    }
    else {
        ColResCounter++;
        index=ColRes(index, ColResCounter);
    	}
    }

    //cout<<targetKey<<" not found\n";

    return false;
}

bool HashedTable::findEntry(const DataRecord* targetKey, DataRecord*& target){
    
    int index= hash(targetKey);
    int ColResCounter=0;
    
    
    while((ColResCounter<ArrSize) && (ArrPtr[index].getStatus() != 0) && ArrPtr[index].getItem()!=0){
        if( (ArrPtr[index].getItem()->get_name()) == targetKey->get_name())
        {
            //cout<<targetKey<<" found at "<<index<<endl;
            target=ArrPtr[index].getItem();
            return true;
        }
        else {
            ColResCounter++;
            index=ColRes(index, ColResCounter);
        }
    }
    
    //cout<<targetKey<<" not found\n";
    
    return false;
}


int HashedTable::ColRes(int index, int count){
    int newIndex;
	//    cout<<"Index "<<index<<" called, but it is full"<<endl;
    
    newIndex=(index+count*count)%ArrSize;
//    cout<<"Attempting ColRes index: "<<newIndex<<endl;
    
    return newIndex;
}

void HashedTable::insert(DataRecord* star){
    
	int ColResCount=0;
    int index=0;
    index = hash(star);
    count++;
    

    while (ColResCount<100){
        
    if (ArrPtr[index].getStatus()!=1){
        ArrPtr[index].setItem(star);
        //cout<<star->get_name()<<" inserted at "<<index<<endl;
		ColCount=ColCount+ColResCount;
    //	cout<<ColCount<<endl;
        return;//shouldn't use break, should use return since we added it.
        }
    else{
        ColResCount++;
		ArrPtr[index].increResCount();
        index=ColRes(index, ColResCount);
        }
    }
	
//   cout<<"Count: "<<count<<endl;
    
}
        
bool HashedTable::remove(const DataRecord* star){ //RO add switched to bool statement
    int ColResCount=0;
    int index= hash(star);
    
    //cout<<"Removing "<<star->get_name()<<endl;
    while (ArrPtr[index].getStatus()!=0 && ColResCount<100){
        if (ArrPtr[index].getItem()->get_name()==star->get_name()){
            ArrPtr[index].setItem(0);
            ArrPtr[index].setStatus(-1);
			ColCount=ColCount-ArrPtr[index].getColResCount();
	        return true;
        }
        else
        {
            ColResCount++;
            index=ColRes(index, ColResCount);

        }
    }

//    cout<<"\nError: entry not found\n";
	return false;
}


/*****************************************************************
shouldn't need to pass in table.
******************************************************************
void HashedTable::clearArray(HashedNode<DataRecord*>* Table){

for(int i=0; i<ArrSize; i++){
Table[i].deleteStar();
Table[i].setStatus(0);
Table[i].setItem(0);
}*/


void HashedTable::clearArray(){
    for(int i=0; i<ArrSize; i++){
		ArrPtr->deleteStar();
		ArrPtr->setStatus(0);
		ArrPtr->setItem(0);
    }
}
