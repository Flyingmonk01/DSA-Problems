// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
// Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.


long long int countt(int coins[], int N, int sum, vector<vector<long long int>>& dp) {
        
        if(sum == 0){
            return 1;
        }
        if(N == 0 || sum < 0)
            return 0;
            
        if(dp[N][sum] != -1){
            return dp[N][sum];
        }
        
        long long int incl = 0;
        if(N-1 >= 0){
            incl = countt(coins, N, sum-coins[N-1], dp);
        }
        long long int excl = countt(coins, N-1, sum, dp);
        
        dp[N][sum] = incl+excl;
        return dp[N][sum];
    }




// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

int solveTab(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int target = 1; target <= amount; target++){
            int mini = INT_MAX;
            for(int i = 0; i < coins.size(); i++){
                if(target-coins[i] >= 0){
                    int ans = dp[target-coins[i]];
                    if(ans != INT_MAX){
                        mini = min(ans+1, mini);
                    }
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solveTab(coins, amount);
        return (ans != INT_MAX) ? ans : -1;
    }