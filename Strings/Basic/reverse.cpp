#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "Nikhil";
    // todo: ################################
    // todo: method 1

    int left =0, right=str.length()-1;
    while(left<right){
        // swapping characters
        swap(s[left], s[right]);
        left++;
        right--;
    }
    cout << "Reversed string: " << s << endl;

    // todo: method 2
    reverse(s.begin(), s.end());
    cout << "Reversed string using reverse function: " << s << endl;
    return 0;

}