// COMSC 210 | Lab 29 | 3 NOV 2025
// IDE: VS Code

// HEADER
// libraries
// fn prototypes
// constants

// STATICS
// tuple definition to store (name, queuetype)
// vector to store names + queuetypes
// map of lists (three different queues)
// vector to store names + queuetypes

// MAIN

    // Open external file to read names + queue
        // Throw error if not opened
    // Read names + queue into vector
    // Close the file

    // Loop over possible number of agents

        // Time simulate; 60 iterations
            // Call addArrival() x times to add queue at steady rate
            // With small probabillity, clusterArrival()

            // Process some names (LIFO), dependent on number of agents

            // calculateWaitTime(nAgents); save if it's the maximum wait time so far

        // Output maximum wait time for this number of agents

    // End simulation

// FUNCTION DEFINITIONS
// addArrival()
    // Select next name from the vector; add it to the corresponding queue

// clusterArrival()
    // Select random number of arrivals
    // call addArrival() that many times

// calculateWaitTime(nAgents)
    // Loop over each queue
        // If queue is not empty
            // Calculate wait time for end of queue
            // Add up total wait time
    // return total wait time