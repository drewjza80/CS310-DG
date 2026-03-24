#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    // Variable declarations
    double netBalance, payment, interestRatePerMonth;
    int d1, d2;

    // Set the locale to the environment's default to enable thousands separators (e.g., 1,000.00)
    cout.imbue(locale("")); 

    // 1. Gather Input
    cout << "Enter the net balance shown on the bill: $";
    cin >> netBalance;
    
    cout << "Enter the payment made: $";
    cin >> payment;
    
    cout << "Enter the number of days in the billing cycle (d1): ";
    cin >> d1;
    
    cout << "Enter the number of days the payment is made before the billing cycle ends (d2): ";
    cin >> d2;
    
    cout << "Enter the interest rate per month (e.g., 0.0152): ";
    cin >> interestRatePerMonth;

    // 2. Perform Calculations
    // Note: d1 is cast to a double automatically during the math operation to prevent integer division issues
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    double interest = averageDailyBalance * interestRatePerMonth;

    // 3. Output the Results
    // fixed and setprecision(2) ensure the output always shows exactly two decimal places
    cout << fixed << setprecision(2);
    
    cout << "\n----------------------------------------\n";
    cout << "Average Daily Balance: $" << averageDailyBalance << "\n";
    cout << "Calculated Interest:   $" << interest << "\n";
    cout << "----------------------------------------\n";

    return 0;
}
