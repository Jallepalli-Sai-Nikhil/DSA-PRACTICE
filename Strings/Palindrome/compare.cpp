#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string &str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

int main() {
    std::string s = "racecar";
    if (isPalindrome(s)) {
        std::cout << s << " is a palindrome." << std::endl;
    } else {
        std::cout << s << " is not a palindrome." << std::endl;
    }
    return 0;
}
