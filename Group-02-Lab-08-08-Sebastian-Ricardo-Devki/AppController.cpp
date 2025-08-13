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

    phoneVectors sample(x, y, z, "");

    string orientation = nn.classify(sample);
    cout << "Detected orientation: " << orientation << "\n";
}

void AppController::ProcessFileInput() {
    string inputFilename = GetStringFromUser("Enter input filename (e.g., unknownData.txt): ");
    ifstream inputFile(inputFilename);

    if (!inputFile.is_open()) {
        cout << "Failed to open input file.\n";
        return;
    }

    ofstream outputFile("result.txt");
    if (!outputFile.is_open()) {
        cout << "Failed to open output file.\n";
        inputFile.close();
        return;
    }

    outputFile << "x y z orientation\n";

    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        double x, y, z;
        if (!(iss >> x >> y >> z)) {
            cout << "Invalid line in input file: " << line << "\n";
            continue;
        }

        phoneVectors sample(x, y, z, "");
        string orientation = nn.classify(sample);
        outputFile << x << " " << y << " " << z << " " << orientation << "\n";
    }

    inputFile.close();
    outputFile.close();
    cout << "Classification complete. Results saved in result.txt\n";
}
