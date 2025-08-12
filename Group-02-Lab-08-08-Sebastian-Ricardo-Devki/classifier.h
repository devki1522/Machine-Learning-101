#pragma once

// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include <string>
#include <vector>
#include "phoneVectors.h"

class classifier {		//abstract base class
public:
	virtual void trainModel(vector<phoneVectors>& trainingData) = 0; // virtual function for training the model with labeled data

	virtual ORIENT classify(phoneVectors& input) = 0;				 // perdict the label for a new data point 
	
	virtual ~classifier() {

	}
};

//nearest neighbor classifier or NNClassifier
class NNClassifier :public classifier {
private:
	vector<phoneVectors> trainingData;
public:
	void trainModel(vector<phoneVectors>& trainingData) override;
	ORIENT classify(phoneVectors& input) override;
};

// AnotherClassifier 
class AnotherClassifier :public classifier {
public:
	void trainModel(vector<phoneVectors>& trainingData) override;
	ORIENT classify(phoneVectors& input) override;

};

//KNNClassifier
class KNNClassifier :public classifier {
public:
	void trainModel(vector<phoneVectors>& trainingData) override;
	ORIENT classify(phoneVectors& input) override;
};