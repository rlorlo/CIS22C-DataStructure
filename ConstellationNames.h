//
//  pointerToDataRecord.h
//  Team project
//
//  Created by Tatiana Karminskaya on 6/2/14.
//  Copyright (c) 2014 t. All rights reserved.
//

#ifndef ConstellationNames_h
#define ConstellationNames_h

#include "DataRecord.h"
#include <vector>
#include <string>

class ConstellationNames
{
private:
	string Constellation;
	vector<DataRecord*> stars;

public:
	ConstellationNames(const string& n) : Constellation(n){};
	void setConstellation(const string& n) { Constellation = n; }
	vector<DataRecord*> getStars() { return stars; }
	string get_Constellation() const{ return Constellation; }
	void insertStars(DataRecord* star) { stars.push_back(star); }

	//overloaded operators
	bool operator>(const ConstellationNames& s) const { return Constellation > s.get_Constellation(); }
	bool operator<(const ConstellationNames& s) const { return Constellation < s.get_Constellation(); }
	bool operator==(const ConstellationNames& s) const { return Constellation == s.get_Constellation(); }

	//void operator=(const pointerToDataRecord& s) {pointer = s.get_pointer();}
};


#endif
