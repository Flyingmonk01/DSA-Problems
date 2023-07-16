// type -- 1
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

int maxProfit(vector<int> &prices)
{

    int diff = 0;
    int mini = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        diff = max(diff, prices[i] - mini);
    }
    return diff;
}





// type -- 2
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

int helper(int buyed, int idx, int& n, vector<int>& prices, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(dp[idx][buyed] != -1) return dp[idx][buyed];
        int profit = 0;


        if(buyed == 1){
            int buyKaro = -prices[idx] + helper(0, idx+1, n, prices, dp);
            int not_Buy = 0 + helper(1, idx+1, n, prices, dp);
            profit = max(buyKaro, not_Buy);
        }
        else{
            int sellKaro = prices[idx] + helper(1, idx+1, n, prices, dp);
            int na_Karo = 0 + helper(0, idx+1, n, prices, dp);
            profit = max(sellKaro, na_Karo);
        }
        return dp[idx][buyed] = profit;
    }



    int helperTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));


        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                
            }
        }
    }

    int maxProfit(vector<int>& prices) {
        int buyed = 1;
        int idx = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(buyed, idx, n, prices, dp);
    }