#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // Constants and variables
    const int NUM_CANDIDATES = 5;
    std::string names[NUM_CANDIDATES];
    int votes[NUM_CANDIDATES];
    
    int totalVotes = 0;
    int maxVotes = 0;
    int winnerIndex = 0;

    std::cout << "--- Local Election Tracker ---" << std::endl;

    // 1. Gather input from the user
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        std::cout << "Enter the last name of candidate " << (i + 1) << ": ";
        std::cin >> names[i];
        
        std::cout << "Enter the number of votes received by " << names[i] << ": ";
        std::cin >> votes[i];

        // Add to total votes
        totalVotes += votes[i];

        // Determine if this candidate is the current leader
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    // 2. Output the formatted results table
    std::cout << "\n" << std::setfill('-') << std::setw(55) << "-" << std::endl;
    std::cout << std::setfill(' '); // Reset fill to space
    std::cout << std::left << std::setw(20) << "Candidate" 
              << std::right << std::setw(15) << "Votes Received" 
              << std::right << std::setw(20) << "% of Total Votes" << std::endl;
    std::cout << std::setfill('-') << std::setw(55) << "-" << std::endl;
    std::cout << std::setfill(' ');

    // 3. Calculate and print individual candidate stats
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        // Calculate percentage (cast to double to prevent integer division)
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100.0;
        
        std::cout << std::left << std::setw(20) << names[i] 
                  << std::right << std::setw(15) << votes[i] 
                  << std::right << std::setw(19) << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;
    }

    // 4. Output the totals and the winner
    std::cout << std::setfill('-') << std::setw(55) << "-" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(20) << "Total" 
              << std::right << std::setw(15) << totalVotes << std::endl;
              
    std::cout << "\nThe Winner of the Election is: **" << names[winnerIndex] << "**!" << std::endl;

    return 0;
}
