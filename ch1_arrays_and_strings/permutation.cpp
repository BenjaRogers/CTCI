#include <iostream>


bool permutation(std::string* str1, std::string* str2) {
    // check for same length
    if (str1->length() != str2->length()) {
        return false;
    }
    // Create counts of each letter to array and compare arrays for equality
    else {
        int charArray1[128] = {};
        int charArray2[128] = {};
        for (int i=0; i<str1->length(); i++) {
            int charInt = int((*str1)[i]);
            charArray1[charInt] ++;
            charInt = int((*str1)[i]);
            charArray2[charInt] ++;
        }
        if (std::equal(std::begin(charArray1), std::end(charArray1), std::begin(charArray2))) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    // TEST
    std::string str1 = "nope";
    std::string str2 = "open";
    // std::string str1 = "nope";
    // std::string str2 = "ope";
    if (permutation(&str1, &str2)) {
        std::cout << str1 << " and " << str2 << " are permutations";
    }
    else {
        std::cout << str1 << " and " << str2 << " are not permutations";
    }
        
    
};

