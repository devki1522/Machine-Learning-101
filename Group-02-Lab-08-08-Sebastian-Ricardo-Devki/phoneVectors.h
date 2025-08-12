#pragma once

// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include <string>

using namespace std;

class phoneVectors {
private:
	double x, y, z;				//vector components to be used for phone orientation
	string phoneOrientation;	// phone orientation
public:
	phoneVectors(double x, double y, double z, const string& phoneOrientation = "");	//constructor
	
	// creating getters to read private data
	double getX();
	double getY();
	double getZ();
	string getPhoneOrientation();

	// creating setters to change values
	void setPhoneOrientation(string& phoneOrientation);
	double distance(phoneVectors& other);
	void print();
};