#pragma once

// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include <string>
#include <fstream>
#include <vector>


using namespace std;

typedef enum phoneOrientation {
	Unknown,
	FaceUp,
	FaceDown,
	PortraitUp,
	PortraitDown,
	LandscapeLeft,
	LandscapeRight
}ORIENT;

class phoneVectors {
private:
	double x, y, z;				//vector components to be used for phone orientation
	ORIENT phoneOrientation;	// phone orientation
public:
	phoneVectors(double x, double y, double z, int phoneOrientation=Unknown);	//constructor
							//cpp is really dumb and doesn't let you implicitly cast ints->enums, which would mess up file reads
	// creating getters to read private data
	double getX();
	double getY();
	double getZ();
	ORIENT getPhoneOrientation();

	// creating setters to change values
	void setPhoneOrientation(ORIENT& phoneOrientation);
	double distance(phoneVectors& other);
	void print();
};


vector<phoneVectors> readVectorsFromFile(string filename, bool orientationknown);
