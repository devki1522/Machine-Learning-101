
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki
#include "classifier.h"
#include "phoneVectors.h"
#include <iostream>

using namespace std;

int main(void) {


	vector<phoneVectors> training = readVectorsFromFile("training.txt",true);

	NNClassifier machine;
	machine.trainModel(training);

	vector<phoneVectors> testing = readVectorsFromFile("testing.txt", false);//intentionally removing the orientations from testing in order to confirm
	vector<phoneVectors>unknown = readVectorsFromFile("unknown.txt", false);

	for (phoneVectors& v : unknown) {
		ORIENT result = machine.classify(v);
		v.setPhoneOrientation(result);
		v.print();
	}


	writeVectorsToFile("results(unknown).txt", unknown);

		

	return 0;
}