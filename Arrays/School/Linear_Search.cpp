#include <bits/stdc++.h>
using namespace std;

int linear(vector<int>& v, int target) {
    int n = v.size();
    for(int i=0; i<n; i++){
        if(v[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    int target = 3;

    cout<<"Found at : "<<linear(v,target);
}