//
//  pointerToDataRecord.h
//  Team project
//
//  Created by Tatiana Karminskaya on 6/2/14.
//  Copyright (c) 2014 t. All rights reserved.
//

#ifndef Team_project_pointerToDataRecord_h
#define Team_project_pointerToDataRecord_h

#include "DataRecord.h"

class pointerToDataRecord
{
private:
    DataRecord* pointer;

public:
    pointerToDataRecord () {pointer = 0;} //Required by the BST's insert function
    pointerToDataRecord(DataRecord* p) {pointer = p;}
    DataRecord *get_pointer() const{return pointer;}
    void set_pointer(DataRecord* pt){pointer = pt;}

    //overloaded operators
    bool operator>(const pointerToDataRecord& s) const {return pointer->get_Distance() > s.pointer->get_Distance();}
	bool operator<(const pointerToDataRecord& s) const {return pointer->get_Distance() < s.pointer->get_Distance();}
    bool operator==(const pointerToDataRecord& s) const {return pointer->get_Distance() == s.pointer->get_Distance();}

    //void operator=(const pointerToDataRecord& s) {pointer = s.get_pointer();}
};


#endif
