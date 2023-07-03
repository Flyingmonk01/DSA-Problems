// Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).


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
    
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> dp(n+1, -1);
        return helper(n, dp);
	}