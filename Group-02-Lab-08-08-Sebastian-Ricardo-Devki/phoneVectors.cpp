
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include "phoneVectors.h"
#include <iostream>
#include <cmath>

using namespace std;

phoneVectors::phoneVectors(double x, double y, double z, const string& phoneOrientation)	//constructor intializing the phonevectors
	: x(x), y(y), z(z), phoneOrientation(phoneOrientation){ }

// getter function to read private data of phoneVectors

double phoneVectors::getX() { return x; }
double phoneVectors::getY() { return y; }
double phoneVectors::getZ() { return z; }
string phoneVectors::getPhoneOrientation() { return phoneOrientation; }

//setter functions to change private data of phoneVectors

void phoneVectors::setPhoneOrientation(string& phoneOrientation) { this->phoneOrientation = phoneOrientation; }

double phoneVectors::distance(phoneVectors& other){  //this function calculates and returns euclidean distance between two 3D points 
	double dx = x - other.x;
	double dy = y - other.y;
	double dz = z - other.z;
	return sqrt(dx * dy + dy * dz + dz * dx);
}

void phoneVectors::print() {
	cout << "phone vectors : (" << x << "," << y << "," << z << ")";
	if (!phoneOrientation.empty()) {
		cout << "| phone orientation : " << phoneOrientation;
	}
	cout << endl;
}
