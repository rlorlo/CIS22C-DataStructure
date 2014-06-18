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
#include <vector>

class DataRecord;

HashedTable::HashedTable(int numNodes) {
	int tempArray[10] = {71,173,281,409,541,659,809,941,1069,1151};
	for(int i =0;i<10;i++)
		primeArray[i] = tempArray[i];
    count=0;
    ColCount=0;
    MaxProbes=0;
    ArrSize=GetNum(numNodes);
    ArrPtr = new HashedNode<DataRecord*>[ArrSize];

}


int HashedTable::hash(const DataRecord* A){
    int index=0;
    double index2=0;
    char word[40];
    int size=(A->get_name()).length();
	strcpy(word, A->get_name().c_str());//forced to changed to _s to use it in vs2013
    //XCODE	strcpy_s(word, A->get_name().c_str());//forced to changed to _s to use it in vs2013
    
    for (int i=0; i<3; i++){
        index2=index2+((word[(1+i)/size])*((word[(0+i)/size])-size));

    }
    
    index=((static_cast<int>(index2))%ArrSize);
    
    return index;
}


int HashedTable::hash(const string target){
    int index=0;
    double index2=0;
    char word[40];
    int size=target.length();
    strcpy(word,(target.c_str()));
//XCODE    strcpy_s(word,(target.c_str()));
    
    for (int i=0; i<3; i++){
        index2=index2+(word[(1+i)/size]*((word[(0+i)/size])-size));
    }
    
    index=((static_cast<int>(index2))%ArrSize);
    
    return index;
}

int HashedTable::ColRes(int index, int count, const DataRecord* target){
    int newIndex;
    double newIndex2;
    char word[40];
    int size=(target->get_name()).length();
	strcpy(word, target->get_name().c_str());//forced to changed to _s to use it in vs2013
    //XCODE	strcpy_s(word, A->get_name().c_str());//forced to changed to _s to use it in vs2013

    
    newIndex2=3*count*word[(7*count)%size]+5*count*word[9/11*size]%ArrSize;
    //    newIndex=((word[7*size/8-count]+word[size-count]*count)*index)%ArrSize; // 280 & 5
    newIndex=((static_cast<int>(newIndex2)));
    return newIndex;
}

int HashedTable::ColRes(int index, int count, const string target){
    int newIndex;
    double newIndex2;
    char word[40];
    int size=target.length();
    strcpy(word,(target.c_str()));
    //XCODE    strcpy_s(word,(target.c_str()));
	
    newIndex2=3*count*word[(7*count)%size]+5*count*word[9/11*size]%ArrSize;
//    newIndex=((word[7*size/8-count]+word[size-count]*count)*index)%ArrSize; // 280 & 5
    newIndex=((static_cast<int>(newIndex2)));
    return newIndex;
}


string HashedTable::printHash() {
	stringstream temp;

    for (int i=0; i<ArrSize; i++){
  //TR CHANGED THIS FOR TESTING
        if(ArrPtr[i].getItem()!=0)
            temp << (ArrPtr[i].getItem())->get_name() << (ArrPtr[i].getColResCount()) << "\n";
        else
            temp << "---\n";
    }
	return temp.str();
}


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
                index=ColRes(index, ColResCounter, key);
            }
        }
        
        return "Item not in list\n"; 
}


string HashedTable::displayStats() {
    stringstream output;
    int i;
    
    float load = (count*100.0)/ArrSize;
    
    output << "There are "<<count<<" stars in the list.\n";
    output<<"The size of the star library is "<<ArrSize<<".\n";
    output<<"Load factor is "<< load<<"%"<<endl<<endl;
    output<< "Total number of collisions: "<< ColCount<<endl;
    output<< "Max Number of Probes: "<<MaxProbes<<endl;
    output<< "List of Stars with max probes: "<<endl;
    for (i=0; i<MaxProbeVector.size(); i++){
            output<<MaxProbeVector[i]->get_name()<<endl;
    }
    
    output<<endl;
    cout << output.str();
    
    cout<<"Bonus: " <<MaxProbeVector[i+1]->get_name()<<endl;
    
    return output.str();
}

int HashedTable::GetNum(int numNodes) {
    int i=0;
    
    for (int i=0; i<10; i++){
        if (numNodes<(primeArray[i]/2))
            return primeArray[i];
    }
    
    return primeArray[i];
}


bool HashedTable::findEntry(string targetKey, DataRecord*& target){
    
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
        index=ColRes(index, ColResCounter, target);
    	}
    }

    //cout<<targetKey<<" not found\n";

    return false;
}

bool HashedTable::findEntry(DataRecord* targetKey, DataRecord*& target){
    
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
            index=ColRes(index, ColResCounter, target);
        }
    }
    
    //cout<<targetKey<<" not found\n";
    
    return false;
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
        if (ColResCount>MaxProbes){
            MaxProbeVector.clear();
            MaxProbes=ColResCount;
            }
        if (ColResCount==MaxProbes){
            MaxProbeVector.push_back(star);
        }
        return;
    }
    else{
        ColResCount++;
		ArrPtr[index].increResCount();
        index=ColRes(index, ColResCount, star);
        }
    }
	
//   cout<<"Count: "<<count<<endl;
    
}
        
bool HashedTable::remove(const DataRecord* star){
    int ColResCount=0;
    int index= hash(star);
    
    while (ArrPtr[index].getStatus()!=0 && ColResCount<MaxProbes){
        if (ArrPtr[index].getItem()->get_name()==star->get_name()){
            ArrPtr[index].setItem(0);
            ArrPtr[index].setStatus(-1);
			ColCount=ColCount-ArrPtr[index].getColResCount();
            for (int i=0; i<MaxProbeVector.size(); i++){
                if (MaxProbeVector[i]->get_name() == star->get_name()){
                    MaxProbeVector.erase(MaxProbeVector.begin()+(i-1));
                }
            }
	        return true;
        }
        else
        {
            ColResCount++;
            index=ColRes(index, ColResCount, star);

        }
    }
    
	return false;
}


void HashedTable::clearArray(){
    for(int i=0; i<ArrSize; i++){
		ArrPtr->deleteStar();
		ArrPtr->setStatus(0);
		ArrPtr->setItem(0);
    }
}

void HashedTable::printOutToFile(ostream& o)
{
	int count = 0;
	for (int i = 0; i<ArrSize; i++){
		if (ArrPtr[i].getItem() != 0)
		{
			count++;
			DataRecord star = *ArrPtr[i].getItem();
			o << right << setw(3) << count << ".  " << left << setw(28) << star.get_name() << setw(23) << star.get_name2() << setw(3) << star.get_RAs_h() << setw(3) << star.get_RAs_m() <<
				setw(9) << star.get_Dec() << setw(14) << star.get_SpT() << setw(6) << right << star.get_VisM() << setw(8) << star.get_AbsM() << setw(6) << star.get_Distance() << endl;
		}
	}
}
