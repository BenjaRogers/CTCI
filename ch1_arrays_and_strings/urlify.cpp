#include <iostream>

// iterate string and replace space with substring '%20' via string replace method
std::string urlify(std::string str) {
    for (int i=0; i<str.length(); i++) {
        if (str[i] == ' ') {
            str.replace(i, 1, "%20", 0, 3);
        }
    }
    return str;
};

int main () 
{
    std::string urlString;
    // Test String
    std::string testStr = "testing urlify method. Let's see how it works.";
    urlString = urlify(testStr);

    std::cout << "\n";
    std::cout << urlString << "\n";
};