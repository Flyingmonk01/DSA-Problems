// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).




    int helper(int W, int wt[], int val[], int index, vector<vector<int>>& dp){
        
        if(index == 0){
            if(wt[index] <= W) return val[index];
            else return 0;
        }
        
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        
        // include call
        int include = 0;
        if(wt[index] <= W){
            include = val[index] + helper(W-wt[index], wt, val, index-1, dp);
        }
        
        int exclude = helper(W, wt, val, index-1, dp);
        
        dp[index][W] = max(include, exclude);
        return dp[index][W];
    }
    
    
    int helperTab(int capacity, int weight[], int value[], int n){
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
        
        for(int w = weight[0]; w <= capacity; w++){
            if(weight[0] <= capacity){
                dp[0][w] = value[0];
            } 
            else{
                dp[0][w] = 0;
            }
        }
        
        
        for(int index = 1; index < n; index++){
            for(int wei = 0; wei <= capacity; wei++){
                // include call
                int include = 0;
                if(weight[index] <= wei){
                    include = value[index] + dp[index-1][wei-weight[index]];
                }
                
                int exclude = 0 + dp[index-1][wei];
                
                dp[index][wei] = max(include, exclude);
            }
        }
        return dp[n-1][capacity];
    }
    
    
    
    
    int helperSO(int capacity, int weight[], int value[], int n){
        vector<int> curr(capacity+1, 0), prev(capacity+1, 0);
        
        for(int w = weight[0]; w <= capacity; w++){
            if(weight[0] <= capacity){
                prev[w] = value[0];
            } 
            else{
                prev[w] = 0;
            }
        }
        
        
        for(int index = 1; index < n; index++){
            for(int wei = 0; wei <= capacity; wei++){
                // include call
                int include = 0;
                if(weight[index] <= wei){
                    include = value[index] + prev[wei-weight[index]];
                }
                
                int exclude = 0 + prev[wei];
                
                curr[wei] = max(include, exclude);
            }
            prev = curr;
        }
        return curr[capacity];
    }
    
    
    
    
    int helperSOO(int capacity, int weight[], int value[], int n){
        vector<int> curr(capacity+1, 0), prev(capacity+1, 0);
        
        for(int w = weight[0]; w <= capacity; w++){
            if(weight[0] <= capacity){
                prev[w] = value[0];
            } 
            else{
                prev[w] = 0;
            }
        }
        
        
        for(int index = 1; index < n; index++){
            for(int wei = capacity; wei >= 0; wei--){
                // include call
                int include = 0;
                if(weight[index] <= wei){
                    include = value[index] + prev[wei-weight[index]];
                }
                
                int exclude = 0 + prev[wei];
                
                prev[wei] = max(include, exclude);
            }
            // prev = curr;
        }
        return prev[capacity];
    }
    
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
       return helperSOO(W, wt, val, n);
    }