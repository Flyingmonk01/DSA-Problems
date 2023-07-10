// Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 10^9 + 7.



const int mod = 1e9 + 7;
    
    long long totalWays(int n, int k, vector<long long>& dp){
        if(n == 1) return k;
        if(n == 2) return k + k*(k-1);
        
        if(dp[n] != -1){
            return dp[n]%mod;
        }
        
        dp[n] = ((totalWays(n-2, k, dp) + totalWays(n-1, k, dp))*(k-1))%mod;
        return dp[n];
    }
    
    long long totalWaysTab(int n, int k){
        vector<long long> dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;
        
        for(int i = 3; i <= n; i++){
            dp[i] = ((dp[i-2] + dp[i-1])*(k-1))%mod;
        }
        return dp[n];
    }
    
    long long totalWaysSO(int n, int k){
        
        if(n == 1) return  k;
        
        long long prev2 = k;
        long long prev1 = k*k;
        long long curr = 0;
        for(int i = 3; i <= n; i++){
            curr = ((prev2 + prev1)*(k-1))%mod;
            
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1, -1);
        return totalWaysSO(n, k);
    }