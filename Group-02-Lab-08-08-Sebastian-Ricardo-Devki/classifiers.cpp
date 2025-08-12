
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include "classifier.h"
#include <iostream>
#include <limits>

//NNClasifier

using namespace std;

void NNClassifier::trainModel(vector<phoneVectors>& trainingData) {
	this->trainingData = trainingData;
}
string NNClassifier::classify(phoneVectors& input) {
	double minDistance = numeric_limits<double>::max();
	string closestOrientation = "unknown";
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
string AnotherClassifier::classify(phoneVectors&) {
	cout << "classification not implemented yet." << endl;
	return "unknown.";
}

//KNNClassifier

void KNNClassifier::trainModel(vector<phoneVectors>&) {
	cout << "Training not implemented yet." << endl;
}
string KNNClassifier::classify(phoneVectors&) {
	cout << "classification not implemented yet." << endl;
	return "unknown.";
}