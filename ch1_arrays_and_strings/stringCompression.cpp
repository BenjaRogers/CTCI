#include <iostream>

std::string compress(std::string s) {
    std::string compressedString;
    int count = 0;
    char l = ' ';
    for (int i=0; i<s.length(); i++) {
        // std::cout << s[i] << "\n";
        // std::cout << count << "\n";
        if (i == 0) {
            compressedString.push_back(s[i]);
            l = s[i];
        }
        else {
            if (s[i] == l) {
                count++;
            }
            else {
                //std::cout << count;
                std::cout << char(count);
                compressedString.push_back(s[i]);
                count = 1;
                l = s[i];
            }
        }
        
    }
    return compressedString;
}

int main() {
    std::string testString = "aabcccccaaa";
    std::string compressedString = compress(testString);
    std::cout << compressedString;
}