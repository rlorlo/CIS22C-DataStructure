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
#include <cstdlib>
#include <string>
#include <sstream>

//class DataRecord;

HashedTable::HashedTable(int numNodes) {
    count=numNodes;
    ArrSize=GetNum();
    ArrPtr = new HashedNode[ArrSize];
    cout<<"Array Size: "<<ArrSize<<endl;
    
    
}


int HashedTable::hash(const DataRecord* A){
    int index=0;
    double index2=0;
    char word[20];

    strcpy(word,(A->get_name().c_str()));
    
//    for (int i=0; i<strlen(word); i++){
      for (int i=0; i<3; i++){
        index2=index2+(word[i]*(word[0])*(i+13));
    }
    
    index=((static_cast<int>(index2))%ArrSize);
    
  //  cout<< " Index: "<<index<<endl;
    
    return index;
        
        
}

void HashedTable::displayStats() {
    int max=0,
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
    
}

int HashedTable::GetNum() {
    int i=0;
    
    for (int i=0; i<10; i++){
        if (count<(primeArray[i]/2))
            return primeArray[i];
    }
        
    return primeArray[i];
}

bool HashedTable::findEntry(const DataRecord* test){
    
    int index= hash(test);
    int ColResCounter=0;
    
    
    while((ColResCounter<ArrSize) && (ArrPtr[index].getStatus() != 0)){
        if( ArrPtr[index].getItem() == test)
    {
        cout<<test->get_name()<<" found at "<<index<<endl;
        return true;
    }
    else {
        ColResCounter++;
        index=ColRes(test, index, ColResCounter);
    }
    }

    cout<<test->get_name()<<" not found\n";

    return true;
}

int HashedTable::ColRes(const DataRecord* A, int index, int count){
    int newIndex;
    cout<<"Index "<<index<<" called, but it is full"<<endl;
    
    newIndex=index+count*count;
    cout<<"Attempting ColRes index: "<<newIndex<<endl;
    
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
        cout<<star->get_name()<<" inserted at "<<index<<endl;
        break;
        }
    else{
        ColResCount++;
        index=ColRes(star, index, ColResCount);
        }
    }
    
    cout<<"Count: "<<count<<endl;
    if (count>(ArrSize*.7))
        newArray();

    
}
        
void HashedTable::remove(const DataRecord* star){
    int ColResCount=0;
    int index= hash(star);
    
    cout<<"Removing "<<star->get_name()<<endl;
    while (ArrPtr[index].getStatus()!=0 && ColResCount<100){
        if (ArrPtr[index].getItem()==star){
            ArrPtr[index].setItem(0);
            ArrPtr[index].setStatus(-1);
            return;
        }
        else
        {
            ColResCount++;
            index=ColRes(star, index, ColResCount);

        }
    }

    cout<<"\nError: entry not found\n";
    
}

void HashedTable::newArray(){
    cout<<"\nMaking new array!\n\n";
    
    HashedTable* HA2= new HashedTable(count);
    int index=0;
    
    for(int i=0; i<this->ArrSize; i++){
        index=0;
        if (ArrPtr[i].getStatus()==1){
        index=HA2->hash(ArrPtr[i].getItem());
        HA2->insert(ArrPtr[i].getItem());
        }
    }
    
    clearArray(ArrPtr);
    
    this->ArrPtr= HA2->ArrPtr;

    clearArray(HA2->ArrPtr);
    delete HA2;

}

void HashedTable::clearArray(HashedNode<DataRecord*>* Table){
    
    for(int i=0; i<ArrSize; i++){
        Table[i].deleteStar();
        Table[i].setStatus(0);
        Table[i].setItem(0);
    }
}
