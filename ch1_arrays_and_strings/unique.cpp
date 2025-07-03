#include <iostream>

// Assume its non-case sensitive (a != A)
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
        std::cout << isUnique(testArray[i]) << "\n";
    }
};
