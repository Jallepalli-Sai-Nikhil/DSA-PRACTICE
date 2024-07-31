#include <iostream>
#include <string>

bool isPalindromeRecursive(const std::string &str, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindromeRecursive(str, left + 1, right - 1);
}

bool isPalindrome(const std::string &str) {
    return isPalindromeRecursive(str, 0, str.length() - 1);
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
