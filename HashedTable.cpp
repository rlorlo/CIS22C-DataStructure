//
//  StarGazers
//  Hashed Array
//  Created by Tom Rico on 5/1/14.
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
    //xcode            strcpy_s(word, A->get_name().c_str());//forced to changed to _s to use it in vs2013
    
    index2=(word[(3)/size]*((word[(2)/size])-size));
    
    index=((static_cast<int>(index2))%ArrSize);
    
    return index;
}


int HashedTable::hash(const string target){
    int index=0;
    double index2=0;
    char word[40];
    int size=target.length();
strcpy(word,(target.c_str()));
    //xcode             strcpy_s(word,(target.c_str()));
    
    
    index2=(word[(3)/size]*((word[(2)/size])-size));
    
    index=((static_cast<int>(index2))%ArrSize);
    
    return index;
}

int HashedTable::ColRes(int index, int count, const DataRecord* target){
    int newIndex;
    double newIndex2;
    char word[40];
    int size=(target->get_name()).length();
    strcpy(word, target->get_name().c_str());//forced to changed to _s to use it in vs2013
    //xcode        strcpy_s(word, target->get_name().c_str());//forced to changed to _s to use it in vs2013

    //newIndex2=(5*count*word[(7*count)%size]+3*count*word[9/11*size])%ArrSize;  //529 & 8
    newIndex2=((word[7*size/8-count]+word[size-count]*count)*index)%ArrSize; // 280 & 5
    newIndex=((static_cast<int>(newIndex2)));
    return newIndex;
}

int HashedTable::ColRes(int index, int count, const string target){
    int newIndex;
    double newIndex2;
    char word[40];
    int size=target.length();
    strcpy(word,(target.c_str()));
    //xcode           strcpy_s(word,(target.c_str()));

    if (count>(7*size/8))
        count=1;
//    newIndex2=(5*count*word[(7*count)%size]+3*count*word[9/11*size])%ArrSize;  //529 & 8
    newIndex2=((word[7*size/8-count]+word[size-count]*count)*index)%ArrSize; // 280 & 5
    newIndex=((static_cast<int>(newIndex2)));
    return newIndex;
}


string HashedTable::printHash() {
	stringstream temp;

    for (int i=0; i<ArrSize; i++){
    if(ArrPtr[i].getItem()!=0)
	    temp << (ArrPtr[i].getItem())->get_name() << "\n";
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
            if( (ArrPtr[index].getItem())->get_name() == key){
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
    
    
    float load = (count*100.0)/ArrSize;
    
    output << "There are "<<count<<" stars in the list.\n";
    output<<"The size of the star library is "<<ArrSize<<".\n";
    output<<"Load factor is "<< load<<"%"<<endl<<endl;
    output<< "Total number of collisions: "<< ColCount<<endl;
    output<< "Max Number of Probes: "<<MaxProbes<<endl;
    output<< "List of Stars with max probes: "<<endl;

	for (size_t i = 0; i<MaxProbeArr.size(); i++){
            output<<MaxProbeArr[i]<<endl;
            output<<findChain(MaxProbeArr[i]);
        }
    
    output<<endl;
    
    return output.str();
}

string HashedTable::findChain(string star){
    stringstream chain;
    int ColResCount=0;
    int index=0;
    index = hash(star);
    
    chain<<"Chain: \n";
    
    while (ColResCount<MaxProbes+1){
        
        
    if(ArrPtr[index].getStatus()==1){
        if (ArrPtr[index].getItem()->get_name()==star){
            chain<<ArrPtr[index].getItem()->get_name()<<endl<<endl;
            return chain.str();
        }
        else{
            chain<<ArrPtr[index].getItem()->get_name()<<", ";
            ColResCount++;
            index=ColRes(index, ColResCount, star);
        }
    }
    else if (ArrPtr[index].getStatus()==-1){
                chain<<"DATA DELETED, ";
                ColResCount++;
                index=ColRes(index, ColResCount, star);
            }
    else if (ArrPtr[index].getStatus()==0){
                return "Chain not found\n";;
            }
        }

        return "Chain not found\n";
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
    
    
    while((ColResCounter<ArrSize) && (ArrPtr[index].getStatus() != 0) ){
        if(ArrPtr[index].getStatus()==1){
            if( (ArrPtr[index].getItem())->get_name() == targetKey){
                target=ArrPtr[index].getItem();
                return true;
            }
        }
        ColResCounter++;
        index=ColRes(index, ColResCounter, targetKey);
    }
    return false;
}


bool HashedTable::findEntry(DataRecord* targetKey, DataRecord*& target){
    
    int index= hash(targetKey);
    int ColResCounter=0;
    
    
    while((ColResCounter<MaxProbes) && (ArrPtr[index].getStatus() != 0) ){
        if(ArrPtr[index].getStatus()==1){
            if( (ArrPtr[index].getItem()->get_name()) == targetKey->get_name()){
                target=ArrPtr[index].getItem();
                return true;
            }
        }

            ColResCounter++;
            index=ColRes(index, ColResCounter, targetKey);
    }
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
        ArrPtr[index].setColCount(ColResCount);
		ColCount=ColCount+ColResCount;
        if (ColResCount>MaxProbes){
			MaxProbeArr.clear();
            MaxProbes=ColResCount;
            }
        if (ColResCount==MaxProbes){
            MaxProbeArr.push_back(star->get_name());
        }
        return;
    }
    else{
        ColResCount++;
        index=ColRes(index, ColResCount, star);
        }
    }
}

bool HashedTable::removeFromProbeArr(DataRecord* star){
    bool deleted=false;
    for (size_t i =0; i<MaxProbeArr.size(); i++){
		if (MaxProbeArr[i] == star->get_name()){
			MaxProbeArr.erase(MaxProbeArr.begin() + i);
            deleted=true;
        }
        if (deleted==true){
            if (MaxProbeArr.empty()){
                MaxProbes = 0;
                for (int j=0; j<ArrSize; j++){
                    if (ArrPtr[j].getColResCount()>MaxProbes){
						MaxProbeArr.clear();
                        MaxProbes=ArrPtr[j].getColResCount();
                    }
					if (ArrPtr[j].getColResCount()==MaxProbes){
						if (ArrPtr[j].getItem() != 0)
						{
							MaxProbeArr.push_back(ArrPtr[j].getItem()->get_name());
						}
                }
                }
            }
        }
				return true;
        }
    return false;
}


bool HashedTable::remove(DataRecord* star){
    int ColResCount=0;
    int index= hash(star);
    
    while (ArrPtr[index].getStatus()!=0 && ColResCount<=MaxProbes){
        if(ArrPtr[index].getStatus()==1){
            if (ArrPtr[index].getItem()->get_name()==star->get_name()){
                ArrPtr[index].setItem(0);
                ArrPtr[index].setStatus(-1);
                ColCount=ColCount-ArrPtr[index].getColResCount();
                ArrPtr[index].setColCount(0);

			for (size_t i = 0; i < MaxProbeArr.size(); i++){
               if (MaxProbeArr[i] == star->get_name()){
                    removeFromProbeArr(star);
                }
            }
	        return true;
            }
        }
            
        
            ColResCount++;
            index=ColRes(index, ColResCount, star);

        
    }
    
	return false;
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
