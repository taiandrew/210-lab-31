// COMSC 210 | Lab 29-31 | 4 NOV 2025
// IDE: VS Code

# include <iostream>
# include <fstream>
# include <list>

# include "passenger.h"

using namespace std;

// Constants
const string FILEPATH = "/Users/andrewtai/Desktop/COMSC_210/projects/210-lab-31/passengers.txt";

static list<Passenger> passengers;


// MAIN
int main() {

    // Load passengers from file
    ifstream inFile;
    inFile.open(FILEPATH);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    string name, queueType;
    while (inFile >> name >> queueType) {
        passengers.emplace_back(name, queueType);
    }
    inFile.close();

    return 0;
}