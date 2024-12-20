#include <iostream>
#include <string>
#include <cctype>

// Function to validate the chain
bool isValidChain(const std::string& input) {
    int n = input.length();

    // Check if the string starts with '(' and ends with ')'
    if (n < 2 || input[0] != '(' || input[n - 1] != ')') return false;

    bool expectAlpha = true; // Expecting an uppercase letter A..Z
    for (int i = 1; i < n - 1; ++i) {
        char ch = input[i];
        if (expectAlpha) {
            if (std::isupper(ch)) {
                expectAlpha = false; // After a letter, expect either ',' or ')'
            }
            else {
                return false; // Error: Not an uppercase letter
            }
        }
        else {
            if (ch == ',') {
                expectAlpha = true; // After ',' expect another letter
            }
            else {
                return false; // Error: Not a comma
            }
        }
    }
    return !expectAlpha; // The last character before ')' must be a letter
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    if (isValidChain(input)) {
        std::cout << "The chain is valid.\n";
    }
    else {
        std::cout << "Error: The chain is invalid.\n";
    }

    return 0;
}
