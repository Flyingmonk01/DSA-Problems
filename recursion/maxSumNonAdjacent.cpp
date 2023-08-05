// Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.



int helper(int *arr, int n, int i, vector<int>& dp){
        if(i >= n) return 0;
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int include = helper(arr, n, i+2, dp) + arr[i];
        
        int exclude = helper(arr, n, i+1, dp) + 0;
        
        dp[i] = max(include, exclude);
        return dp[i];
    }
    
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+1, -1);
	    return helper(arr, n, 0, dp);
	}