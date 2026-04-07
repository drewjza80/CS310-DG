#include <iostream>

using namespace std;

int main() {
    // =======================================================================
    // Variable Declarations
    // =======================================================================
    int a; // Time to prepare the first dish
    int b; // Additional time for each subsequent dish
    int t; // Total time available

    // =======================================================================
    // Input
    // =======================================================================
    cout << "Enter the time required for the first dish (a): ";
    cin >> a;

    cout << "Enter the extra time added per subsequent dish (b): ";
    cin >> b;

    cout << "Enter the total time available (t): ";
    cin >> t;

    // =======================================================================
    // Calculations
    // =======================================================================
    int dishesPrepared = 0;
    int timeSpent = 0;
    int currentDishTime = a;

    // Loop continues as long as Bianca has enough time to finish the next dish
    while ((timeSpent + currentDishTime) <= t) {
        timeSpent += currentDishTime;    // Add the time of the current dish to the total time spent
        dishesPrepared++;                // Increment the count of finished dishes
        currentDishTime += b;            // Calculate the time required for the next dish
    }

    // =======================================================================
    // Output
    // =======================================================================
    cout << "\n----------------------------------------\n";
    cout << "Result: Bianca can prepare " << dishesPrepared << " dishes in " << t << " minutes.\n";
    cout << "Total time actually used: " << timeSpent << " minutes.\n";
    cout << "----------------------------------------\n";

    return 0;
}
