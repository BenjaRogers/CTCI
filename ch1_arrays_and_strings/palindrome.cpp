#include <iostream>
#include <map>

bool palindrome(std::string str) {
    std::map <char, int> letters;
    int charLength = 0;
    // pull letters into a dictionary object {letter: occurence count}
    for (int i=0; i<str.length(); i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            letters[c] ++;
            charLength ++;
        }
    }
    char* palindromeString = new char[charLength];
    int count = 0;
    int oddCount = 0;

    // iterate dictionary and write letters w/ even occurence count to front and back of character string
    for (const auto& [let, num] : letters) {
        //std::cout << let << " " << num << "\n";
        if (num % 2 == 0) {
            for (int i=0; i<num; i=i+2) {
                palindromeString[0+count] = let;
                palindromeString[charLength-1-count] = let;
                count ++;
            }
        }
        // if odd occurence -> write to the middle of character string
        else {
            palindromeString[charLength / 2] = let;
            oddCount++;
            if (oddCount > 1) {
                return false;
            }
        }
    }

    //std::cout << evenArray;
    std::cout << palindromeString;
    return true;
};

int main() {
// Tests
    std::string testStrings[] = {"Tactz Coammllllza"};
    bool isPalindrome = palindrome(testStrings[0]);
    if (isPalindrome) {
        std::cout << " is a pallindrome for " << testStrings[0];
    }
    else {
        std::cout << testStrings[0] << " is not a palindrome";
    }
};