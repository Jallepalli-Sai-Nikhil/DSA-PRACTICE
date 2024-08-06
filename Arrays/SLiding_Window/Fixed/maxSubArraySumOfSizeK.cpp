#include >bits/stdc++.h>
using namespace std;

int findMaxSubarraySumOfSizeK(vector<int> arr, int k, int n){
        if(n < k) return -1;
        
        int windowSum = 0;
        int maxSum = 0;
        
        
        for(int i = 0; i<k;i++){
            windowSum += arr[i];
        }
        
        finalSum = windowSum;
        for(int i = k; i<n;i++){
            windowSum = arr[i] - arr[i-k];
            maxSum = max(windowSum, finalSum);
        }
        
        return maxSUm;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int k = 4;
    cout<<findMaxSubarraySumOfSizeK(arr, k, arr.size());
    return 0;
}