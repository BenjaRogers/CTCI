#include <iostream>
#include <map>

bool palindrome(std::string str) {
    std::map <char, int> letters;
    
    for (int i=0; i<str.length(); i++) {
        char c = tolower(str[i]);
        letters[c] ++;
        std::cout << letters[c] << "\n";
    }
    return true;
};

int main() {
// Tests
    std::string testStrings[] = {"Tact Coa"};
    palindrome(testStrings[0]);
};