
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


int helper(int n, vector<int>& prices, int idx, int lowest, int& maxi){
        if(idx >= prices.size()){
            return maxi;
        }
        
        if(prices[lowest] > prices[idx]){
            lowest = idx;
        } 
        maxi += max(maxi, prices[idx]-prices[lowest]);
        return helper(n, prices, idx+1, lowest, maxi);
    }
  
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int maxi = -1;
        return helper(n, prices, 0, 0, maxi);
    }