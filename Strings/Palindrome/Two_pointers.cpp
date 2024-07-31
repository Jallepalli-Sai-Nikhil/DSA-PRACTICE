#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &str){
    int left = 0;
    int right = str.size() -1;

    while(left < right){
        if(str[left] != str[right]){
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main(){
    std::string s = "racecar";
    if (isPalindrome(s)) {
        std::cout << s << " is a palindrome." << std::endl;
    } else {
        std::cout << s << " is not a palindrome." << std::endl;
    }
    return 0;
}