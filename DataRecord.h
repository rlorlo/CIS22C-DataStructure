//  DataRecord.h
//  Team project
//  Team Name: Stargazers

#ifndef Team_project_Element_h
#define Team_project_Element_h

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class DataRecord
{
private:

	string name;       // Name of the star in constellation
	string name2;      // Usual name of the star
	float VisM;        // Visual magnitude
	float AbsM;        // Absolute magnitude
	int Distance;      // Distance, in light years
	string SpT;        // Spectral type (will be converted to color below)
	float Dec;         // Equatorial coordinate, Declination, in degrees
	//float RAs;       // Equatorial coordinate, Right ascension, in degrees
        int RAs_h ;        // Equatorial coordinate, Right ascension, (hours and minutes, will be converted to degrees below)
        int RAs_m;

public:
	//accessors
	string get_name() const { return name; }
	string get_con() const
	{
		string f = name;
		string s;
		istringstream iss(f);
		iss >> s;
		ostringstream oss;
		oss << iss.rdbuf();
		return oss.str();
	}
	string get_name2() const { return name2; }
	float get_VisM() const { return VisM; }
	float get_AbsM() const { return AbsM; }
	int get_Distance() const { return Distance; }
	string get_SpT() const { return SpT; }
	float get_Dec() const { return Dec; }
	//float get_RAs() const { return Dec; }
        int get_RAs_h() const {return RAs_h;}
        int get_RAs_m() const {return RAs_m;}
        
     
	//mutators
	void set_name(string n){ name = n; }
	void set_name2(string n2){ name2 = n2; }
	void set_VisM(float V){ VisM = V; }
	void set_AbsM(float A){ AbsM = A; }
	void set_Distance(int D){ Distance = D; }
	void set_SpT(string S){ SpT = S; }
	void set_Dec(float De){ Dec = De; }
        
	//void set_RAs(float Ra){ RAs = Ra; }
        void set_RAs_h(int RA_m) { RAs_m = RA_m; }
        void set_RAs_m(int RA_h) { RAs_h = RA_h; }
 
	/*void printStar() const {
		cout << "Name of the star in constellation: " << name
			<< "\nUsual name of the star: " << name2
			<< "\nVisual magnitude: " << VisM
			<< "\nAbsolute magnitude: " << AbsM
			<< "\nDistance, in light years: " << Distance
			<< "\nSpectral type: " << SpT
			<< "\nEquatorial coordinate, Declination, in degrees: " << Dec
			<< "\nEquatorial coordinate, Right ascension, in hours"< RAs_h << endl;
                        << "\nEquatorial coordinate, Right ascension, in mins: " << RAs_m << endl;
	}*/

	//Overloaded operators
	bool operator>(const DataRecord& s) const { return Distance > s.get_Distance(); }
	bool operator<(const DataRecord& s) const { return Distance < s.get_Distance(); }
	bool operator==(const DataRecord& s) const { return Distance == s.get_Distance(); }

	//friend overloaded stream insertion operator
	friend ostream &operator<<(ostream& output, const DataRecord& star)
	{
		output << star.get_name() << "(" << star.get_name2() << ")" << ": " << star.get_Distance() << endl;
		return output;
	}
};

#endif
