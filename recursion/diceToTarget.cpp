// You have n dice, and each die has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.


int mod = 1000000007;

    int helper(int dice, int faces, int target, vector<vector<int>>& dp){
        // base case
        if(dice == 0 && target == 0) return 1;
        if(target < 0) return 0;
        if(target == 0 && dice != 0) return 0;
        if(dice == 0 && target != 0) return 0;
        
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }    
        
        int ans = 0;
        for(int i = 1; i <= min(faces, target); i++){
             ans = (ans + helper(dice-1, faces, target-i, dp)) % mod;
        }
        return dp[dice][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return helper(n, k, target, dp);
    }