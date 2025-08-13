
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include "classifier.h"
#include <iostream>
#include <limits>


using namespace std;


//NNClasifier

void NNClassifier::trainModel(vector<phoneVectors>& trainingData) {
	this->trainingData = trainingData;
}


ORIENT NNClassifier::classify(phoneVectors& input) {
	double minDistance = numeric_limits<double>::max();
	ORIENT closestOrientation = Unknown;

	for (auto& point : trainingData) {
		double distance = input.distance(point);
		if (distance < minDistance) {
			minDistance = distance;
			closestOrientation = point.getPhoneOrientation();
		}
	}
	return closestOrientation;
}



//AnotherClassifier

void AnotherClassifier::trainModel(vector<phoneVectors>&) {
	cout << "Training not implemented yet." << endl;
}
ORIENT AnotherClassifier::classify(phoneVectors&) {
	cout << "classification not implemented yet." << endl;
	return Unknown;
}

//KNNClassifier

void KNNClassifier::trainModel(vector<phoneVectors>&) {
	cout << "Training not implemented yet." << endl;
}
ORIENT KNNClassifier::classify(phoneVectors&) {
	cout << "classification not implemented yet." << endl;
	return Unknown;
}