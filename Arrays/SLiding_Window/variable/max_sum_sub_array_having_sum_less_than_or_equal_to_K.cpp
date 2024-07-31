class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
    int left = 0, right = 0;
    long long currentSum = 0;
    long long maxSum = 0;
	    
	    while(right < n){
	        currentSum += arr[right];
	        
	        while(currentSum > sum && left <= right){
	            currentSum = currentSum - arr[left];
	            left++;
	        }
	        
	        
	        if(currentSum <= sum){
	            maxSum = max(currentSum, maxSum);
	        }
	        
	        right++;
	    }
	    return maxSum;
	}	 

};
	  
