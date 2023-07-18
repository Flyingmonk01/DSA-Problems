// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.




bool helper(vector<int>& nums, int index, int n, int target, vector<vector<int>>& dp){
        if(index >= n){
            return false;
        }
        if(target == 0) return true;
        if(target < 0) return false;

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        // include
        bool include = helper(nums, index+1, n, target-nums[index], dp);
        bool exclude = helper(nums, index+1, n, target, dp);
        return dp[index][target] = include||exclude;
    }


    bool helperTab(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int index = 0; index < n; index++){
            dp[index][0] = 1;
        }

        for(int index = n-1; index >= 0; index--){
            for(int targt = 1; targt <= target; targt++){
                bool include = false;
                if(targt-nums[index] >= 0){
                    include = dp[index+1][targt-nums[index]];
                }
                bool exclude = dp[index+1][targt];
                dp[index][targt] = include||exclude;
            }
        }
        return dp[0][target];
    }


    bool helperSO(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> curr(target+1, 0), next(target+1, 0);
        for(int index = 0; index < n; index++){
            curr[0] = 1;
        }

        for(int index = n-1; index >= 0; index--){
            for(int targt = 1; targt <= target; targt++){
                bool include = false;
                if(targt-nums[index] >= 0){
                    include = next[targt-nums[index]];
                }
                bool exclude = next[targt];
                curr[targt] = include||exclude;
            }
            next = curr;
        }
        return curr[target];
    }



    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return helper(nums, 0, n, target, dp);
        return helperSO(nums, target);
    }