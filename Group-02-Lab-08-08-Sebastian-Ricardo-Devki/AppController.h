// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#pragma once
#include <string>
#include "classifier.h"

class AppController
{
public:
    void Run();

private:
    int DisplayMainMenu();
    int DisplayNNClassifierMenu();
    void HandleClassifierChoice(int choice);

    void ProcessSingleSample();
    void ProcessFileInput();

    double GetDoubleFromUser(const std::string& prompt);
    std::string GetStringFromUser(const std::string& prompt);

    NNClassifier nn;
    AnotherClassifier another;
    KNNClassifier knn;
};
