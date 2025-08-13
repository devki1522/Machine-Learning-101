
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include "phoneVectors.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

//constructor intializing the phonevectors
phoneVectors::phoneVectors(double x, double y, double z, int phoneOrientation) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->phoneOrientation = (ORIENT)phoneOrientation;
		//wow this is super dumb why cant I just do it like in C?
}

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
	return sqrt(dx*dx + dy*dy + dz*dz); //would take care of any negatives too
//	return sqrt(dx * dy + dy * dz + dz * dx);
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

	cout << "phone vectors : (" << x << "," << y << "," << z << ") | phone orientation : " << phoneOrientation<<endl;
}



vector<phoneVectors> readVectorsFromFile(string filename, bool orientationknown) {
	//i barely have any idea how any of this stuff works tbh

	vector<phoneVectors> fileVectors;
	string temp; //for storing each line as we read it
	string temp2; //for storing each comma separated value as we change it to int
	//temp vars for storing read values
	double x;
	double y;
	double z;
	ORIENT o=Unknown; //default value in case file doesnt give em

	ifstream fp(filename);
	if (!fp.is_open()) {
		//can't think of another way of doing this since this function has to return
		fprintf(stderr, "error opening file, might not exist\n");
		exit(EXIT_FAILURE);
	}


	//takes the file a single line at a time
	while (getline(fp, temp)) {
		istringstream line(temp);//turns it into a stream or something

		getline(line, temp2, ',');//splits by comma
		x = stod(temp2);

		getline(line, temp2, ',');//splits by comma
		y = stod(temp2);

		getline(line, temp2, ',');//should work despite the newline
		z = stod(temp2);

		//really ugly way of doing things i know
		if (orientationknown) {
			getline(line, temp2, ',');
			o =(ORIENT) stoi(temp2);
			//why are enums so annoying in cpp?
		}


		phoneVectors v(x, y, z,o);
		fileVectors.push_back(v);
	}

	fp.close();

	return fileVectors;
}

void writeVectorsToFile(string filename, vector<phoneVectors> data) {
	ofstream fp(filename);
	if (!fp.is_open()) {
		fprintf(stderr, "problem opening output file\n");
		return; //dont have to exit failure here since function is void
	}

	for (phoneVectors v : data) {
		fp << v.getX() << "," << v.getY() << "," << v.getZ() <<","<<v.getPhoneOrientation()<< endl;
	}

	fp.close();
}