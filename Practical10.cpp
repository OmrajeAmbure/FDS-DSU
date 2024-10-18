#include <iostream>
#include <stack>
#include <cctype>
#include <string>

// Function to clean the input string (only alphanumeric, converted to lowercase)
std::string cleanString(const std::string& input) {
    std::string cleaned;
    for (char c : input) {
        if (std::isalnum(c)) {
            cleaned += std::tolower(c);
        }
    }
    return cleaned;
}

// Function to print the original string and its reversed cleaned version
void printOriginalAndReversed(const std::string& input) {
    std::string cleanedInput = cleanString(input);
    std::stack<char> charStack;

    // Push cleaned characters onto the stack
    for (char c : cleanedInput) {
        charStack.push(c);
    }

    // Print the original string
    std::cout << "Original string: " << input << std::endl;

    // Print the reversed cleaned string
    std::cout << "Reversed cleaned string: ";
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    std::cout << std::endl;
}

// Function to check if the input string is a palindrome
bool isPalindrome(const std::string& input) {
    std::string cleanedInput = cleanString(input);
    std::stack<char> charStack;

    // Push cleaned input characters onto the stack
    for (char c : cleanedInput) {
        charStack.push(c);
    }

    // Compare cleaned input characters with characters popped from the stack
    for (char c : cleanedInput) {
        if (c != charStack.top()) {
            return false; // Not a palindrome
        }
        charStack.pop();
    }

    return true; // The string is a palindrome
}

int main() {
    std::string input;

    // Get input from the user
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    
    // Print original and reversed versions of the string
    printOriginalAndReversed(input);
    
    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
