// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.


// Memoization
int helper(int n, vector<int>& dp){
        // base case
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = n;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1+helper(n-i*i, dp));
            
        }
        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }


// Tabulation
