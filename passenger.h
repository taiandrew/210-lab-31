#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

using namespace std;

class Passenger {

private:
    string name;
    string queueType;

public:
    // Constructor; default regular queue
    Passenger (string name, string queueType="regular") : name(name), queueType(queueType) {}

    // Getters
    string getName() const { return name; }
    string getQueueType() const { return queueType; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setQueueType(const string& newQueueType) { queueType = newQueueType; }

};

#endif