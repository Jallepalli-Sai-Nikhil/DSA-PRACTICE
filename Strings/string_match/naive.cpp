#include <iostream>
#include <string>

void naiveStringMatching(const std::string &text, const std::string &pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    
    // Loop through the text
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        // Check the substring from i to i + patternLength - 1
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        // If the inner loop didn't break, we found a match
        if (j == patternLength) {
            std::cout << "Pattern found at index " << i << std::endl;
        }
    }
}

int main() {
    std::string text = "ABCDEF";
    std::string pattern = "ABC";
    
    naiveStringMatching(text, pattern);
    return 0;
}
