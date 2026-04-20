#include <iostream>
#include <string>
#include <cctype> // Required for the tolower() function

using namespace std;

// ========================================================================
// Function Prototypes
// ========================================================================
bool isVowel(char c);
void removeVowels(string& str);

// ========================================================================
// Main Execution
// ========================================================================
int main() {
    string userInput;

    // Prompt the user for a string
    cout << "Enter a string: ";
    // Use getline to ensure we capture spaces if the user types a full sentence
    getline(cin, userInput);

    // Call the function to process the string
    removeVowels(userInput);

    // Output the final result
    cout << "String after removing vowels: " << userInput << endl;

    return 0;
}

// ========================================================================
// Function Definitions
// ========================================================================

/**
 * Determines whether a given character is a vowel.
 * @param c The character to check.
 * @return True if the character is a vowel, false otherwise.
 */
bool isVowel(char c) {
    // Convert the character to lowercase to simplify our checks
    char lowerC = tolower(c);
    
    // Check against the five standard vowels
    return (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u');
}

/**
 * Removes all vowels from a string in-place using the substr function.
 * @param str A reference to the string being modified.
 */
void removeVowels(string& str) {
    size_t i = 0;
    
    // Loop through the string until the end
    while (i < str.length()) {
        if (isVowel(str[i])) {
            // If a vowel is found, use substr to rebuild the string without it.
            // str.substr(0, i) takes everything BEFORE the vowel.
            // str.substr(i + 1) takes everything AFTER the vowel.
            str = str.substr(0, i) + str.substr(i + 1);
            
            // Note: We DO NOT increment 'i' here. Because we just removed a character,
            // the entire right side of the string shifted left. The next character to
            // check is now sitting at the exact same index 'i'.
        } else {
            // If it's a consonant or symbol, simply move to the next index.
            i++;
        }
    }
}
