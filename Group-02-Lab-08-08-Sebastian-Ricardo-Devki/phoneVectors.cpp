
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include "phoneVectors.h"
#include <iostream>
#include <cmath>

using namespace std;

phoneVectors::phoneVectors(double x, double y, double z, ORIENT phoneOrientation)	//constructor intializing the phonevectors
	: x(x), y(y), z(z), phoneOrientation(phoneOrientation){ }

// getter function to read private data of phoneVectors

double phoneVectors::getX() { return x; }
double phoneVectors::getY() { return y; }
double phoneVectors::getZ() { return z; }
ORIENT phoneVectors::getPhoneOrientation() { return phoneOrientation; }

//setter functions to change private data of phoneVectors

void phoneVectors::setPhoneOrientation(ORIENT& phoneOrientation) { this->phoneOrientation = phoneOrientation; }

double phoneVectors::distance(phoneVectors& other){  //this function calculates and returns euclidean distance between two 3D points 
	double dx = x - other.x;
	double dy = y - other.y;
	double dz = z - other.z;
	//I don't think the math's right here?
	//shouldn't it be sqrt(dx^2 + dy^2 + dz^2) ??
	//return sqrt(dx*dx + dy*dy + dz*dz); //would take care of any negatives too
	return sqrt(dx * dy + dy * dz + dz * dx);
}

void phoneVectors::print() {

	//takes a lot of space but I can't think of another way to do this
	string oriout;
	switch (phoneOrientation) {
	case Unknown:
		oriout = "unknown";
		break;
	case FaceUp:
		oriout = "faceup";
		break;
	case FaceDown:
		oriout = "facedown";
		break;
	case PortraitUp:
		oriout = "portrait";
		break;
	case PortraitDown:
		oriout = "portrait upside down";
		break;
	case LandscapeLeft:
		oriout = "landscapeleft";
		break;
	case LandscapeRight:
		oriout = "landscapeRight";
		break;
	}

	cout << "phone vectors : (" << x << "," << y << "," << z << ") | phone orientation : " << oriout<<endl;
}
