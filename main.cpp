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
void testingDriver();

// CONSTANTS
const string FILEPATH = "/Users/andrewtai/Desktop/COMSC_210/projects/210-lab-31/passengers.txt";
const int MAX_AGENTS = 5;


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
    /*
    if (!testPassengerList(inputPassengers)) {
        cout << "TEST FAILURE: testPassengerList()" << endl;
        return 1;
    }
    printPassengerList(inputPassengers);
    printNames(inputPassengers);
    */
    testingDriver();

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
    // Prints all passengers with queue types in a list of passengers
    for (const Passenger& passenger : passengers){
        passenger.printPassenger();
    }
}

void printNames(const list<Passenger>& passengers) {
    // Prints only the names of passengers in a list of passengers
    for (const Passenger& passenger : passengers) {
        cout << passenger.getName() << endl;
    }
}

void addPassenger(map<string, list<string>>& queues, const Passenger& passenger) {
    // Add a passenger to the appropriate queue based on their queue type
    // Args:
    //   queues - map of lists representing the different queues
    //   passenger - Passenger object to add
    string queueType = passenger.getQueueType();
    queues[queueType].push_back(passenger.getName());
}

float calculateWaitTime(const map<string, list<string>>& queues, int nAgents) {
    // Calculate total wait time across all queues based on number of agents
    // Args:
    //   queues - map of lists containing the different queues. MUST BE regular, priority, extra
    //   nAgents - number of agents processing passengers
    // Returns: float total wait time

    float totalWaitTime = 0.0;

    // Logic: Each agent can process one "unit" per time
    // Regular and priority contribute 1 unit per passenger, extra contributes 2 units

    totalWaitTime += (queues.at("regular").size() + queues.at("priority").size());
    totalWaitTime += (queues.at("extra").size() * 2);

    return totalWaitTime / nAgents;

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

void testingDriver() {
    // Driver function for testing

    // Initialize map of lists
    map<string, list<string>> queues = {
        {"regular", list<string>()},
        {"priority", list<string>()},
        {"extra", list<string>()}
    };

    // Calculate wait time with no passengers and 2 agents
    cout << "Wait time with no passengers: " << calculateWaitTime(queues, 2) << endl;

    // Print each queue size
    for (const auto& pair : queues) {
        cout << "Queue Type: " << pair.first << ", Size: " << pair.second.size() << endl;
    }

    // A couple passengers to test
    Passenger p1("Alice", "regular");
    Passenger p2("Bob", "priority");

    // Add to queues
    addPassenger(queues, p1);
    addPassenger(queues, p2);

     // Print each queue size
    for (const auto& pair : queues) {
        cout << "Queue Type: " << pair.first << ", Size: " << pair.second.size() << endl;
    }

    // Calculate wait time with passengers
    cout << "Wait time with 2 passengers and 1 agent: " << calculateWaitTime(queues, 1) << endl;
    cout << "Wait time with 2 passengers and 2 agents: " << calculateWaitTime(queues, 2) << endl;
}