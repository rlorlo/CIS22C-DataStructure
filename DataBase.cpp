//  DataBase.cpp
//
//  Team project
//
//  Created by Tatiana Karminskaya on 5/22/14.


#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <cctype>


DataBase::DataBase() //: DataStack(0)
{
    arraySize = 0;
	DataTree = new BinarySearchTree<pointerToDataRecord>();
	DataHash = new HashedTable();
}


