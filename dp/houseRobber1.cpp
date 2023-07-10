// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


int houseRob(vector<int>& nums, int n){
        // base case
        if(n < 0) return 0;
        if(n == 0) return nums[0];
        // include
        int include = houseRob(nums, n-2) + nums[n];
        // exclude
        int exclude = houseRob(nums, n-1);

        return max(include, exclude);
    }

    int houseRobMem(vector<int>& nums, int n, vector<int>& dp){
        if(n < 0) return 0;
        if(n == 0) return nums[0];

        // step 3: check if dp[n]/ ans is present or not?
        if(dp[n] != -1){
            return dp[n];
        }

        int include = houseRobMem(nums, n-2, dp) + nums[n];
        int exclude = houseRobMem(nums, n-1, dp);

        // step 2 : ans store in dp
        dp[n] = max(include, exclude);
        return dp[n];
    }


    int houseRobTab(vector<int>& nums, int n){
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];

        for(int i = 1; i <= n; i++){
            int temp = 0;
            if(i-2 >= 0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1];

            dp[i] = max(include, exclude);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        // // step 1 : Create a dp array
        // vector<int> dp(n+1, -1);
        // int ans = houseRobMem(nums, n, dp);
        // return ans;

        return houseRobTab(nums, n);
    }