// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.



int helper(int n, vector<int>& days, vector<int>& costs, int idx, vector<int>& dp){
        // base case
        if(idx >= n) return 0;

        if(dp[idx] != -1){
            return dp[idx];
        }

        // for day 1
        int forFirstDay = costs[0] + helper(n, days, costs, idx+1, dp);

        int i;
        // for 7 days
        for(i = idx; i < n && days[i] < days[idx] + 7; i++);
        int forSecondDay = costs[1] + helper(n, days, costs, i, dp);

        // for 30 days
        for(i = idx; i < n && days[i] < days[idx] + 30; i++);
        int forThirdDay = costs[2] + helper(n, days, costs, i, dp);

        dp[idx] = min(forFirstDay, min(forSecondDay, forThirdDay));
        return dp[idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        return helper(days.size(), days, costs, 0, dp);
    }