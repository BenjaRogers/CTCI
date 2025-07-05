#include <iostream>

// Check if 1 replacement operation makes strings equivalent
bool checkReplace(std::string s1, std::string s2) {
    // int numOperations = 0;
    // std::cout << " replacement check ";
    for (int i=0; i<s1.length(); i++) {
        if (s1[i] != s2[i]) {
            s1.replace(i, 1, s2.substr(i, 1));
        }
        if (s1 == s2) {
            std::cout << " one away with replacement at index " << i << "\n";
            return true;
            
        }
        else {
            std:: cout << "not one away with replacement" << "\n";
            return false;
        }
    }
    return false;
};

// check if one insertion operation makes strings equivalent
bool checkInsert(std::string* shortStr, std::string* longStr) {
    //iterate through shorter string(s1) and insert s2[i] where s1[i] != s2[i]
    for (int i=0; i<shortStr->length(); i++) {
        if ((*shortStr)[i] != (*longStr)[i]) {
            shortStr->insert(i, longStr->substr(i, 1));
            if (*shortStr == *longStr) {
                std::cout << " one away with insertion at index " << i << "\n";
                return true;
            }
            else {
                std::cout << " not one away with insertion." << "\n";
                return false;
            }
        }
    }
    return false;
};

bool oneAway(std::string str1, std::string str2) {
    // Compare lengths of strings to determine operation
    int str1Len = str1.length();
    int str2Len = str2.length();
    std::string* longer;
    std::string* shorter;
    // if length difference is > 1 return false
    if(abs(str1Len - str2Len) > 1) {
        return false;
    }
    // Check for replace if lengths are the same
    if (str1Len == str2Len) {
        if (str1 == str2) {
            return true;
        }
        return checkReplace(str1, str2);
    }
    // Determine which string is shorter/longer.
    (str1Len > str2Len) ? (longer = &str1, shorter = &str2) : (longer = &str2, shorter = &str1);
    return checkInsert(shorter, longer);
    //std::cout << str1Len << " " << str2Len << " " << *longer<< " " << *shorter << "\n";
    return true;
}


int main() {
    std::string testStr1[] = {"pale", "ple"};
    std::string testStr2[] = {"pales", "pale"};
    std::string testStr3[] = {"pale", "bale"};
    std::string testStr4[] = {"pale", "bake"};
    std::cout << "Strings " << testStr4[0] << " and " << testStr4[1] << " are";
    oneAway(testStr4[0], testStr4[1]);
};