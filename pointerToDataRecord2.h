//
//  pointerToDataRecord.h
//  Team project
//
//  Created by Tatiana Karminskaya on 6/2/14.
//  Copyright (c) 2014 t. All rights reserved.
//

#ifndef Team_project_pointerToDataRecord2_h
#define Team_project_pointerToDataRecord2_h

#include "DataRecord.h"

class pointerToDataRecord2
{
private:
    DataRecord* pointer;

public:
    pointerToDataRecord2 () {pointer = 0;} //Required by the BST's insert function
    pointerToDataRecord2(DataRecord* p) {pointer = p;}
    DataRecord *get_pointer() const{return pointer;}
    void set_pointer(DataRecord* pt){pointer = pt;}

    //overloaded operators
    bool operator>(const pointerToDataRecord2& s) const {return pointer->get_con() > s.pointer->get_con();}
	bool operator<(const pointerToDataRecord2& s) const {return pointer->get_con() < s.pointer->get_con();}
    bool operator==(const pointerToDataRecord2& s) const {return pointer->get_con() == s.pointer->get_con();}

    //void operator=(const pointerToDataRecord& s) {pointer = s.get_pointer();}
};


#endif