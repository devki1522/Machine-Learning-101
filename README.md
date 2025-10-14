```mermaid
classDiagram
    direction LR

    class phoneVectors {
        - double x
        - double y
        - double z
        - ORIENT phoneOrientation
        + phoneVectors(double x, double y, double z, int phoneOrientation=Unknown)
        + double getX()
        + double getY()
        + double getZ()
        + ORIENT getPhoneOrientation()
        + string getOrientationAsString()
        + void setPhoneOrientation(ORIENT orien)
        + double distance(phoneVectors& other)
        + void print()
    }

    class classifier {
        <<abstract>>
        + void trainModel(vector<phoneVectors>& trainingData)*
        + ORIENT classify(phoneVectors& input)*
        + ~classifier()
    }

    class NNClassifier {
        - vector<phoneVectors> trainingData
        + void trainModel(vector<phoneVectors>& trainingData)
        + ORIENT classify(phoneVectors& input)
    }

    class AnotherClassifier {
        + void trainModel(vector<phoneVectors>& trainingData)
        + ORIENT classify(phoneVectors& input)
    }

    class KNNClassifier {
        + void trainModel(vector<phoneVectors>& trainingData)
        + ORIENT classify(phoneVectors& input)
    }

    class AppController {
        + void Run()
        + NNClassifier nn
        + AnotherClassifier another
        + KNNClassifier knn
        - int DisplayMainMenu()
        - int DisplayNNClassifierMenu()
        - void HandleClassifierChoice(int choice)
        - void ProcessSingleSample()
        - void ProcessFileInput()
        - double GetDoubleFromUser(string prompt)
        - string GetStringFromUser(string prompt)
    }

    class FileIO {
        + vector<phoneVectors> readVectorsFromFile(string filename, bool orientationknown)
        + void writeVectorsToFile(string filename, vector<phoneVectors> data)
    }

   
    classifier <|-- NNClassifier
    classifier <|-- AnotherClassifier
    classifier <|-- KNNClassifier

    AppController --> NNClassifier
    AppController --> AnotherClassifier
    AppController --> KNNClassifier
```

```mermaid
flowchart TD

A[Start System] --> B[Initialize SCADA & Connect Trucks]
B --> C[Receive Truck Status Data]
C --> D{Truck Idle?}

D -- Yes --> E[Assign Load via Dispatcher]
D -- No --> F[Monitor Active Trucks]

E --> G[Truck Executes Delivery]
F --> G

G --> H[Update Fuel, Location, Load Status]
H --> I[Store Data in Database & Update HMI]
I --> J{Any Alerts?}

J -- Yes --> K[Trigger Alarm & Notify Dispatcher]
J -- No --> L[Continue Monitoring]

K --> L
L --> M{Delivery Complete?}

M -- Yes --> N[Set Truck to Idle]
M -- No --> C

N --> C
C --> O[System Shutdown]
O --> P[Save Logs & Disconnect]
P --> Q[End]

```

    classifier --> phoneVectors
    NNClassifier --> phoneVectors

    FileIO --> phoneVectors
    AppController --> FileIO
