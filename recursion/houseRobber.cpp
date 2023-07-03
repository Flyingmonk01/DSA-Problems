// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


int helper(int arr[], int n, int idx, vector<int>& dp){
        if(idx >= n) return 0;
        
        if(dp[idx] != 0) return dp[idx];
        
        int inc = helper(arr, n, idx+2, dp) + arr[idx];
        int exc = helper(arr, n, idx+1, dp) + 0;
    
        dp[idx] = max(inc, exc);
        return dp[idx];
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+1, 0);
        return helper(arr, n, 0, dp);   
    }