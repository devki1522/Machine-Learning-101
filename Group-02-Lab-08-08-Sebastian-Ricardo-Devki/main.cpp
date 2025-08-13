
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki
#include "classifier.h"
#include "phoneVectors.h"
#include <iostream>

using namespace std;

int main(void) {


	vector<phoneVectors> training = readVectorsFromFile("training.txt",true);

	NNClassifier machine;
	machine.trainModel(training);

	vector<phoneVectors> testing = { phoneVectors(-0.17778,-0.04568,-0.98301),phoneVectors(-0.17765,-0.04547,-0.98304),phoneVectors(-0.03205,-0.23794,-0.97075),
		phoneVectors(-0.27181,-0.16695,-0.94776),phoneVectors(-0.08683,-0.34201,-0.93568),phoneVectors(0.05951,-0.16744,0.98408),phoneVectors(0.42008,-0.05597,0.90576),
		phoneVectors(0.3811,-0.03899,0.92371),phoneVectors(-0.15083,-0.33631,0.92959),phoneVectors(0.44038,0.01346,0.89771),phoneVectors(-0.01429,-0.99807,-0.06051),
		phoneVectors(0.0048,-0.96534,-0.26095),phoneVectors(-0.12484,-0.98771,0.09409),phoneVectors(0.01774,-0.99978,-0.01092),phoneVectors(-0.26325,-0.933,-0.24538),
		phoneVectors(0.00982,0.99868,-0.05038),phoneVectors(-0.07058,0.99706,-0.02986),phoneVectors(-0.18741,0.97813,-0.09022),phoneVectors(0.04945,0.96554,-0.25553),
		phoneVectors(0.9978,-0.05244,-0.04047),phoneVectors(0.99827,-0.04471,-0.03825),phoneVectors(0.93264,-0.03448,-0.35916),phoneVectors(0.88866,-0.01717,0.45824),
		phoneVectors(0.88988,-0.45391,0.04563),phoneVectors(-0.89759,0.01899,-0.44043),phoneVectors(-0.67688,0.02461,-0.73569),phoneVectors(-0.99965,-0.02597,-0.00571),
		phoneVectors(-0.9762,0.13291,-0.1714),phoneVectors(-0.96562,-0.19291,-0.17428) };

	for (phoneVectors v : testing) {
		ORIENT result = machine.classify(v);
		v.setPhoneOrientation(result);
		v.print();
	}

		

	return 0;
}