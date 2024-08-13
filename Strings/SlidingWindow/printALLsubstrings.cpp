#include <iostream>
#include <string>

void printSubstrings(const std::string& s, int length) {
    if (length > s.size()) {
        std::cout << "Length is greater than the string length." << std::endl;
        return;
    }

    for (size_t i = 0; i <= s.size() - length; ++i) {
        std::cout << s.substr(i, length) << std::endl;
    }
}

int main() {
    std::string str = "abcdef";
    int length = 3;

    printSubstrings(str, length);

    return 0;
}
