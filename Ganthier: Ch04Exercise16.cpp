#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // =======================================================================
    // Named Constants
    // =======================================================================
    const double OPTION_1_DELIVERY = 5000.00;
    const double OPTION_1_PUBLISHED = 20000.00;
    
    const double OPTION_2_RATE = 0.125; // 12.5%
    
    const double OPTION_3_BASE_RATE = 0.10;  // 10%
    const double OPTION_3_BONUS_RATE = 0.14; // 14%
    const int OPTION_3_THRESHOLD = 4000;

    // =======================================================================
    // Variables
    // =======================================================================
    double netPrice;
    int copiesSold;

    // =======================================================================
    // Input
    // =======================================================================
    cout << "Enter the net price of each copy of the novel: $";
    cin >> netPrice;
    
    cout << "Enter the estimated number of copies that will be sold: ";
    cin >> copiesSold;

    // =======================================================================
    // Calculations
    // =======================================================================
    
    // Option 1: Fixed payouts
    double option1 = OPTION_1_DELIVERY + OPTION_1_PUBLISHED;
    
    // Option 2: Flat percentage of all sales
    double option2 = copiesSold * netPrice * OPTION_2_RATE;
    
    // Option 3: Tiered percentage based on threshold
    double option3;
    if (copiesSold <= OPTION_3_THRESHOLD) {
        option3 = copiesSold * netPrice * OPTION_3_BASE_RATE;
    } else {
        // Calculate the first 4000 copies, then add the remaining copies at the higher rate
        double baseRoyalties = OPTION_3_THRESHOLD * netPrice * OPTION_3_BASE_RATE;
        double bonusRoyalties = (copiesSold - OPTION_3_THRESHOLD) * netPrice * OPTION_3_BONUS_RATE;
        option3 = baseRoyalties + bonusRoyalties;
    }

    // =======================================================================
    // Output
    // =======================================================================
    
    // Format the console output for standard currency (two decimal places)
    cout << fixed << setprecision(2);
    
    cout << "\n----------------------------------------\n";
    cout << "Royalty Estimates\n";
    cout << "----------------------------------------\n";
    cout << "Option 1 (Fixed):   $" << option1 << "\n";
    cout << "Option 2 (12.5%):   $" << option2 << "\n";
    cout << "Option 3 (Tiered):  $" << option3 << "\n";
    cout << "----------------------------------------\n";

    // Determine the best option
    cout << "Best Choice: ";
    if (option1 >= option2 && option1 >= option3) {
        cout << "Option 1 yields the highest royalties.\n";
    } else if (option2 >= option1 && option2 >= option3) {
        cout << "Option 2 yields the highest royalties.\n";
    } else {
        cout << "Option 3 yields the highest royalties.\n";
    }
    cout << "----------------------------------------\n";

    return 0;
}
