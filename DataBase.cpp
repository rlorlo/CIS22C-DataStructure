//  DataBase.cpp
//
//  Team project
//
//  Created by Tatiana Karminskaya on 5/22/14.


#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <cctype>


DataBase::DataBase()
{

    Element* tempStar;
    
    DataTree = new BinarySearchTree<Element*>();
    DataHash = new HashedTable<Element*>();

    //File Data members
	ifstream File;
    string fileName = "brightstars.txt";
    
    //Data members for Element.h
    string n;       // Name of the star in constellation
    string n2;      // Usual name of the star
    float V;        // Visual magnitude
    float A;        // Absolute magnitude
    int D;          // Distance, in light years
    string S;       // Spectral type (will be converted to color below)
    float De;       // Equatorial coordinate, Declination, in degrees
    struct RA       // Equatorial coordinate, Right ascension, (hours and minutes, will be converted to degrees below)
    {
        int hours;
        int mins;
    };
    float Ra;      // Equatorial coordinate, Right ascension, in degrees
    
    // Data members to parse the file
    string buffer;
    char buf[3];
    
	
    //Open the file
    File.open(fileName);
	while (!File)
    {
        cout << "Error opening file\nEnter filename: ";
        cin >> fileName;
        File.open(fileName);
    }

    //Read data from the file
    while(!File.eof())
	{
	
    File >> buffer;
    File >> n;
    File >> buffer;
    n = n+ " " + buffer;
    File.get(buf, sizeof(buf));
    
    if(buf[1]!=32)
    {
        File >>buffer;
        n = n + buf + buffer;
    }
    File >> buffer;
       
    
    if(isdigit(buffer[0]))
    {
         n2 = "NoName";
    }
    else
    {
        n2 = buffer;
        File.get(buf, sizeof(buf));
        
        if(buf[1]!=32)
        {
            File >> buffer;
            n2 = n2 + buf + buffer;
        }
        File >> buffer;
    }
    RA tempRA;
    tempRA.hours = stoi(buffer);
    File >> buffer;
    tempRA.mins = stoi(buffer);
        
    //Convert RA to decimal degrees
    Ra = tempRA.hours / 15 +tempRA.mins / 4;
    
    File >> buffer;
    De = stof(buffer);
    
    File >> buffer;
    File >> buffer;
    File >> buffer;
    S = buffer;
    File >> buffer;
    V = stof(buffer);
    File >> buffer;
    A = stof(buffer);
    File >> buffer;
    File >> buffer;
    File >> buffer;
    D =stoi(buffer);
    
        tempStar = new Element();
   
        tempStar->set_name(n);
        tempStar->set_name2(n2);
        tempStar->set_VisM(V);
        tempStar->set_Distance(D);
        tempStar->set_SpT(S);
        tempStar->set_Dec(De);
        tempStar->set_RAs(Ra);
        
    //insert pointers into BST and Hash Table
    DataTree->insertBST(tempStar);
    DataHash->insertHash(tempStar);
	
   
    }
    
    // Close the file
	File.close();
}

void DataBase :: Display()
{
    
}

void filePrint(Element & star, ofstream File)
{
	File << left << setw(23) << star.get_name() << setw(23) << star.get_name2() << setw(10) << star.get_VisM() << setw(10) << star.get_AbsM() << setw(10) << star.get_SpT() << setw(10) << star.get_Distance() << endl;
}

void DataBase::Quit()
{
    //rewrite file
    ofstream File;
    string fileName = "brightstars.txt";
    File.open(fileName);
	while (!File)
    {
        cout << "Error opening file\nEnter filename: ";
        cin >> fileName;
        File.open(fileName);
    }
   DataTree->inOrder(filePrint);
    
}
