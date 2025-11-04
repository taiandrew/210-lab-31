// COMSC 210 | Lab 29-31 | 4 NOV 2025
// IDE: VS Code

# include <iostream>
# include <fstream>
# include <map>
# include <list>
# include <string>
# include <sstream>

# include "passenger.h"

using namespace std;

// FUNCTION PROTOTYPES
void printPassengerList(const list<Passenger>&);
void printNames(const list<Passenger>&);
bool testPassengerList(const list<Passenger>&);

// CONSTANTS
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

    // Testing read correctly into inputPassengers
    if (!testPassengerList(inputPassengers)) {
        cout << "TEST FAILURE: testPassengerList()" << endl;
        return 1;
    }
    //printPassengerList(inputPassengers);
    //printNames(inputPassengers);

    // Initialize map of lists for queues
    map<string, list<string>> queues = {
        {"regular", list<string>()},
        {"priority", list<string>()},
        {"extra", list<string>()}
    };

    return 0;
}

// FUNCTION DEFINITIONS
void printPassengerList(const list<Passenger>& passengers) {
    for (const Passenger& passenger : passengers) {
        passenger.printPassenger();
    }
}

void printNames(const list<Passenger>& passengers) {
    for (const Passenger& passenger : passengers) {
        cout << passenger.getName() << endl;
    }
}

// TESTING FNs
bool testPassengerList(const list<Passenger>& passengers) {
    // Check that a passenger list has contains Passenger objects, with valid queue types, and is nonempty
    // Arg: passengers - list of Passenger objects
    // Returns: false if any test fails
    
    // Check first passenger conforms
    auto it = passengers.begin();
    if (it == passengers.end()) return false; // List is empty
    if (it->getQueueType() != "regular" && it->getQueueType() != "priority" && it->getQueueType() != "extra") return false;

    // Check last passenger conforms
    it = passengers.end();
    it--;
    if (it->getQueueType() != "regular" && it->getQueueType() != "priority" && it->getQueueType() != "extra") return false;
    
    return true;
}