// COMSC 210 | Lab 29-31 | 4 NOV 2025
// IDE: VS Code

# include <iostream>
# include <fstream>
# include <list>
# include <string>
# include <sstream>

# include "passenger.h"

using namespace std;

// FUNCTION PROTOTYPES
void printPassengerList(const list<Passenger>&);

// Constants
const string FILEPATH = "/Users/andrewtai/Desktop/COMSC_210/projects/210-lab-31/passengers.txt";



// MAIN
int main() {

    // Load passengers from file
    list<Passenger> inputPassengers;
    ifstream inFile;
    inFile.open(FILEPATH);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    string name, queueType, line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, queueType, ',');
        inputPassengers.emplace_back(name, queueType);
    }
    inFile.close();

    printPassengerList(inputPassengers);

    return 0;
}

// FUNCTION DEFINITIONS
void printPassengerList(const list<Passenger>& passengers) {
    for (const Passenger& passenger : passengers) {
        passenger.printPassenger();
    }
}