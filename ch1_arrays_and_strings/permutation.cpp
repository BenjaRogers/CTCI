#include <iostream>

// 
bool permutation(std::string* str1, std::string* str2) {
    // check for same length
    if (str1->length() != str2->length()) {
        return false;
    }

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

    std::cout << permutation(&str1, &str2);
};

