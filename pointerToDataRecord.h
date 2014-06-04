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
    DataRecord* pointer;
    
public:
    pointerToDataRecord(DataRecord* p) {pointer = p};
    DataRecord* get_pointer() const{return pointer;};
    void set_pointer(p){pointer = p;}
    
    //overloaded operators
    bool operator>(const pointerToDataRecord& s) const {return this.pointer->get_Distance() > s.pointer->get_Distance();}
	bool operator<(const pointerToDataRecord& s) const {return this.pointer->get_Distance() < s.pointer->get_Distance();}
    bool operator==(const pointerToDataRecord& s) const {return this.pointer->get_Distance() == s.pointer->get_Distance();
}


#endif
