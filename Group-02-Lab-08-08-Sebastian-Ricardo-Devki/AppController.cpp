// AppController.cpp
// Group 02 - Lab - 08 - 09 - Sebastian - Ricardo - Devki

#include "AppController.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

void AppController::Run() {
    while (true) {
        int choice = DisplayMainMenu();
        HandleClassifierChoice(choice);
        if (choice == 0) break;
    }
}

int AppController::DisplayMainMenu() {
    cout << "\nChoose classifier (or 0 to exit):\n";
    cout << "1. NNClassifier\n";
    cout << "2. AnotherClassifier\n";
    cout << "3. KNNClassifier\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    while (cin.fail() || choice < 0 || choice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter 0-3: ";
        cin >> choice;
    }
    return choice;
}

int AppController::DisplayNNClassifierMenu() {
    cout << "\nNNClassifier options:\n";
    cout << "1. Enter single (x,y,z) sample\n";
    cout << "2. Process file input\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter 1 or 2: ";
        cin >> choice;
    }
    return choice;
}

void AppController::HandleClassifierChoice(int choice) {
    switch (choice) {
    case 0:
        cout << "Exiting program.\n";
        break;
    case 1: {
        int nnChoice = DisplayNNClassifierMenu();
        if (nnChoice == 1) {
            ProcessSingleSample();
        }
        else {
            ProcessFileInput();
        }
        break;
    }
    case 2:
        cout << "AnotherClassifier not implemented yet.\n";
        break;
    case 3:
        cout << "KNNClassifier not implemented yet.\n";
        break;
    default:
        cout << "Invalid choice.\n";
    }
}

double AppController::GetDoubleFromUser(const std::string& prompt) {
    double val;
    cout << prompt;
    cin >> val;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. " << prompt;
        cin >> val;
    }
    return val;
}


string AppController::GetStringFromUser(const std::string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    return input;
}

void AppController::ProcessSingleSample() {
    double x = GetDoubleFromUser("Enter x: ");
    double y = GetDoubleFromUser("Enter y: ");
    double z = GetDoubleFromUser("Enter z: ");

    phoneVectors sample(x, y, z);

    ORIENT orientation = nn.classify(sample);
    //takes a lot of space but I can't think of another way to do this
    string oriout;
    switch (orientation) {
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
    cout << "Detected orientation: " << oriout << "\n";
}

void AppController::ProcessFileInput() {
    string inputFilename = GetStringFromUser("Enter input filename (e.g., unknownData.txt): ");

    vector<phoneVectors> inputvectors =readVectorsFromFile(inputFilename, false);

    for (phoneVectors& v : inputvectors) {
        ORIENT result = nn.classify(v);
        v.setPhoneOrientation(result);
    }

    writeVectorsToFile("results-" + inputFilename,inputvectors);


    cout << "Classification complete. Results saved in result.txt\n";
}
