#include <iostream>
#include <vector>

bool isRotation(std::string s1, std::string s2, int* offset) {
    int start=0;
    // must be equal length to be rotations -- return false if not
    if (s1.length() != s2.length()) {
        return false;
    }

    // Return false if first letter in s1 is not in s2 - otherwise save s2 start index to variable start
    start = s2.find(s1[0]);
    if (start == -1) {
        return false;
    }
    *offset = start;

    // Iterate through both strings from first letter index+1
    for (int i=1; i<s1.length(); i++) {
        int s2Index = (start + i > s2.length()-1) ? start + i - s2.length() : start + i;
        char l1 = s1[i];
        char l2 = s2[s2Index];
        if (s1[i] != s2[s2Index]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1 = "waterbottle";
    std::string str2 = "erbottlewat";
    int offset = 0;
    if(isRotation(str1, str2, &offset)) {
        std::cout << str1 << " and " << str2 << " are rotations with an offset of " << offset;
    }
    else {
        std::cout << str1 << " and " << str2 << " are not rotations.";
    }
    std::cout << offset;
}