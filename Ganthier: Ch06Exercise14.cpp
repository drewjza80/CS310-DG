#include <iostream>
#include <iomanip>

using namespace std;

// ========================================================================
// Function Prototype
// ========================================================================
double calculateBillingAmount(double hourlyRate, int consultingTime, bool isLowIncome);

// ========================================================================
// Main Execution
// ========================================================================
int main() {
    double hourlyRate;
    int consultingTime;
    char incomeResponse;
    bool isLowIncome;

    // 1. Gather Input
    cout << "Enter the regular hourly rate: $";
    cin >> hourlyRate;

    cout << "Enter the total consulting time (in minutes): ";
    cin >> consultingTime;

    cout << "Does the person have a low income (<= $25,000)? (y/n): ";
    cin >> incomeResponse;

    // Convert the char response to a boolean value
    if (incomeResponse == 'y' || incomeResponse == 'Y') {
        isLowIncome = true;
    } else {
        isLowIncome = false;
    }

    // 2. Perform Calculation via User-Defined Function
    double finalBill = calculateBillingAmount(hourlyRate, consultingTime, isLowIncome);

    // 3. Output the Result
    cout << fixed << setprecision(2);
    cout << "\n----------------------------------------\n";
    cout << "Billing Summary\n";
    cout << "----------------------------------------\n";
    cout << "Hourly Rate:     $" << hourlyRate << "\n";
    cout << "Consulting Time: " << consultingTime << " minutes\n";
    cout << "Low Income:      " << (isLowIncome ? "Yes" : "No") << "\n";
    cout << "Total Charges:   $" << finalBill << "\n";
    cout << "----------------------------------------\n";

    return 0;
}

// ========================================================================
// Function Definition
// ========================================================================
/**
 * Calculates the billing amount based on income status and time thresholds.
 * * @param hourlyRate     The standard hourly rate for the service.
 * @param consultingTime The total time spent in minutes.
 * @param isLowIncome    True if the user makes <= 25,000; otherwise false.
 * @return               The final calculated billing amount.
 */
double calculateBillingAmount(double hourlyRate, int consultingTime, bool isLowIncome) {
    double billingAmount = 0.0;
    int billableMinutes = 0;

    if (isLowIncome) {
        // Low income rule: first 30 minutes are free
        if (consultingTime > 30) {
            billableMinutes = consultingTime - 30;
            // 40% of the hourly rate for billable time
            billingAmount = hourlyRate * 0.40 * (billableMinutes / 60.0);
        }
    } else {
        // Normal income rule: first 20 minutes are free
        if (consultingTime > 20) {
            billableMinutes = consultingTime - 20;
            // 70% of the hourly rate for billable time
            billingAmount = hourlyRate * 0.70 * (billableMinutes / 60.0);
        }
    }

    return billingAmount;
}
