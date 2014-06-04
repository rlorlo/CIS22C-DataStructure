//  DataRecord.h
//  Team project
//  Team Name: Stargazers

#ifndef Team_project_Element_h
#define Team_project_Element_h

#include <iomanip>
#include <iostream>
using namespace std;

class DataRecord
{
private:
    /* ************************************************************************
    Maybe change name to FullName and in comments write key. As for name2 change
    it to commonName.  This will help us differentiate between the two of them.
    ************************************************************************ */
    string name;       // Name of the star in constellation
    string name2;      // Usual name of the star
    float VisM;        // Visual magnitude
    float AbsM;        // Absolute magnitude
    int Distance;      // Distance, in light years
    string SpT;        // Spectral type (will be converted to color below)
    float Dec;         // Equatorial coordinate, Declination, in degrees
    float RAs;         // Equatorial coordinate, Right ascension, in degrees

public:
    //accessors
    string get_name() const {return name;}
    string get_name2() const {return name2;}
    float get_VisM() const {return VisM;}
    float get_AbsM() const {return AbsM;}
    int get_Distance() const {return Distance;}
    string get_SpT() const {return SpT;}
    float get_Dec() const {return Dec;}
    float get_RAs() const {return Dec;}
    //mutators
    void set_name(string n){name = n;}
    void set_name2(string n2){name2 = n2;}
    void set_VisM(float V){VisM = V;}
    void set_Distance(int D){Distance = D;}
    void set_SpT(string S){SpT = S;}
    void set_Dec(float De){Dec = De;}
    void set_RAs(float Ra){RAs = Ra;}

	void printStar() const {
    cout <<"Name of the star in constellation: "<<name
    <<"\nUsual name of the star: "<<name2
    <<"\nVisual magnitude: "<<VisM
    <<"\nAbsolute magnitude: "<<AbsM
    <<"\nDistance, in light years: "<<Distance
    <<"\nSpectral type: "<<SpT
    <<"\nEquatorial coordinate, Declination, in degrees: "<<Dec
    <<"\nEquatorial coordinate, Right ascension, in degrees: "<<RAs<<endl;
    }

    //Overloaded operators
    bool operator>(const DataRecord& s) const {return Distance > s.get_Distance();}
	bool operator<(const DataRecord& s) const {return Distance < s.get_Distance();}
	bool operator==(const DataRecord& s) const {return Distance == s.get_Distance();}

    //friend overloaded stream insertion operator
/*    friend ostream &operator<<(ostream& output, const DataRecord& star)
    {
    output<<name<<"("<<name2<<")"<<": "<<Distance<<endl;
    return output;
    }
 */
};

#endif
