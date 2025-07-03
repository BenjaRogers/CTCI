#include <iostream>

// Assume its case sensitive (a != A)
// Uses data structures other than string
bool isUnique(std::string str) {
    bool charArray[128] = {}; // bools indexed by char->int value
    for (int i=0; i<str.length(); i++) {
        // Cast char to int, and check if indexed int value has already occured.
        int charInt = int(str[i]);
        if (charArray[charInt]) {
            return false;
        }
        else {
            charArray[charInt] = true;
        }
    }
    return true;
};

int main () {
    // Array of test strings.
    std::string testArray[] = {"hello", "abcdefghijklmnopA", "12345", "1,21", ",.,!"};

    int arraySize = sizeof(testArray) / sizeof(testArray[0]);
    for (int i=0; i<arraySize; i++) {
        //std::cout << testArray[i].length() << "\n";
        std::cout << "String '" << testArray[i] << "'";
        if (isUnique(testArray[i])) {
            std::cout << "is unique." << "\n";
        }
        else {
            std::cout << "is not unique." << "\n";
        }
        
    }
};
