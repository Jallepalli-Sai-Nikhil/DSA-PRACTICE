#include <iostream>
#include <string>
#include <stack>

bool isPalindrome(const std::string &str) {
    std::stack<char> charStack;
    
    for (char c : str) {
        charStack.push(c);
    }
    
    for (char c : str) {
        if (c != charStack.top()) {
            return false;
        }
        charStack.pop();
    }
    return true;
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
