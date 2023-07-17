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



    // int helperTab(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(2, 0));

    //     for(int index = n-1; index >= 0; index--){
    //         for(int buy = 0; buy < 2; buy++){
    //             int profit = 0;
    //             if(buy == 1){
    //                 int buyKaro = -prices[index] + dp[index+1][0];
    //                 int not_Buy = 0 + dp[index+1][1];
    //                 profit = max(buyKaro, not_Buy);
    //             }
    //             else{
    //                 int sellKaro = prices[index] + dp[index+1][1];
    //                 int na_Karo = 0 + dp[index+1][0];
    //                 profit = max(sellKaro, na_Karo);
    //             }
    //             dp[index][buy] = profit;
    //         }
    //     }
    //     return dp[0][1];
    // }


    int helperTab(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;
                if(buy == 1){
                    int buyKaro = -prices[index] + next[0];
                    int not_Buy = 0 + next[1];
                    profit = max(buyKaro, not_Buy);
                }
                else{
                    int sellKaro = prices[index] + next[1];
                    int na_Karo = 0 + next[0];
                    profit = max(sellKaro, na_Karo);
                }
                curr[buy] = profit;
                cout << next[buy] << " ";
            }
            next = curr;
            cout << endl;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        int buyed = 1;
        int idx = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(buyed, idx, n, prices, dp);
    }





    // type -- 3

//     You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


// int helper(vector<int>& prices, int buy, int index, int limit, vector<vector<vector<int>>>& dp){
    //     if(index >= prices.size()){
    //         return 0;
    //     }
    //     if(limit == 0){
    //         return 0;
    //     }
    //     if(dp[index][buy][limit] != -1){
    //         return dp[index][buy][limit];
    //     }
    //     int profit = 0;
    //     if(buy == 1){
    //         profit = max(-prices[index] + helper(prices, 0, index+1, limit, dp), helper(prices, 1, index+1, limit, dp));
    //     }
    //     else{
    //         profit = max(prices[index] + helper(prices, 1, index+1, limit-1, dp), helper(prices, 0, index+1, limit, dp));
    //     }
    //     return dp[index][buy][limit] = profit;
    // }

    // int helper(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));


    //     for(int index = n-1; index >= 0; index--){
    //         int profit = 0;
    //         for(int buy = 0; buy <= 1; buy++){
    //             for(int limit = 2; limit > 0; limit--){
    //                 if(buy == 1){
    //                     profit = max(-prices[index] + dp[index+1][0][limit], dp[index+1][1][limit]);
    //                 }
    //                 else{
    //                     profit = max(prices[index] + dp[index+1][1][limit-1], dp[index+1][0][limit]);
    //                 }
    //                 dp[index][buy][limit] = profit;
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }


    int helper(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));


        for(int index = n-1; index >= 0; index--){
            int profit = 0;
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 2; limit > 0; limit--){
                    if(buy == 1){
                        profit = max(-prices[index] + next[0][limit], next[1][limit]);
                    }
                    else{
                        profit = max(prices[index] + next[1][limit-1], next[0][limit]);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int index = 0;
        int limit = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(limit+1, -1)));
        int ans = helper(prices);
        return ans;
    }
 



//  type -- 4
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


int helper(vector<int>& prices, int& k){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));


        for(int index = n-1; index >= 0; index--){
            int profit = 0;
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = k; limit > 0; limit--){
                    if(buy == 1){
                        profit = max(-prices[index] + next[0][limit], next[1][limit]);
                    }
                    else{
                        profit = max(prices[index] + next[1][limit-1], next[0][limit]);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return helper(prices, k);
    }




    // type -- 5
//     You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note:

// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

// int helper(int& fee, int buy, int idx, int& n, vector<int>& prices, vector<vector<int>>& dp){
    //     if(idx >= n) return 0;
    //     if(dp[idx][buy] != -1) return dp[idx][buy];
    //     int profit = 0;


    //     if(buy == 1){
    //         int buyKaro = -prices[idx] + helper(fee, 0, idx+1, n, prices, dp);
    //         int not_Buy = 0 + helper(fee, 1, idx+1, n, prices, dp);
    //         profit = max(buyKaro, not_Buy);
    //     }
    //     else{
    //         int sellKaro = prices[idx] - fee + helper(fee, 1, idx+1, n, prices, dp);
    //         int na_Karo = 0 + helper(fee, 0, idx+1, n, prices, dp);
    //         profit = max(sellKaro, na_Karo);
    //     }
    //     return dp[idx][buy] = profit;
    // }

    int helperTab(int& fee, vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy < 2; buy++){
                int profit = 0;
                if(buy == 1){
                    int buyKaro = -prices[index] + next[0];
                    int not_Buy = 0 + next[1];
                    profit = max(buyKaro, not_Buy);
                }
                else{
                    int sellKaro = prices[index] - fee + next[1];
                    int na_Karo = 0 + next[0];
                    profit = max(sellKaro, na_Karo);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return helperTab(fee, prices);
    }