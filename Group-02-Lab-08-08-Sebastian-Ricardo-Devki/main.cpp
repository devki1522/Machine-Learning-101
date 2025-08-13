
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki
#include "classifier.h"
#include "phoneVectors.h"
#include <iostream>
#include "AppController.h"

using namespace std;

int main(void) {


	vector<phoneVectors> training = readVectorsFromFile("training.txt",true);

	AppController action;
	action.nn.trainModel(training);
	action.Run();


	return 0;
}