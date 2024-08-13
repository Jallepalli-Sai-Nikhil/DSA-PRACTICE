#include <bits/stdc++.h>
using namespace std;


int main() {
    std::string str = "hello world";
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << str << std::endl;  // Output: HELLO WORLD
    
    std::string str = "hello world";
    for (char &c : str) {
        c = std::toupper(c);
    }
    std::cout << str << std::endl; 


    std::string str = "hello world";
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
    }
    std::cout << str << std::endl;

// bitwise
    char c = 'b';          // 'b' has ASCII value 98
char upper = c & '_';  // '_' has ASCII value 95 (binary: 0101 1111)
    
    return 0;
}
