// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

 



 class Solution {
public:
    static bool comp(vector<int> &a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else{
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(temp.back()<envelopes[i][1]){
                temp.push_back(envelopes[i][1]);
            }
            else{
                auto ind=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[ind]=envelopes[i][1];
            }
        }
        return temp.size();
    }

    int recursion(vector<vector<int>>& env, int curr, int prev, vector<vector<int>>& dp){
        if(curr >= env.size()) return 0;

        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        // include
        int include = 0;
        if(prev == -1 || env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1]){
            include = 1 + recursion(env, curr+1, curr, dp);
        }
        int exclude = recursion(env, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }

    int tabulation(vector<vector<int>>& env){
        int n = env.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // include
                int include = 0;
                if(prev == -1 || env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1]){
                    include = 1 +dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int SO(vector<vector<int>>& env){
        int n = env.size();
        vector<int> current(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // include
                int include = 0;
                if(prev == -1 || env[prev][0] < env[curr][0] && env[prev][1] < env[curr][1]){
                    include = 1 + next[curr+1];
                }
                int exclude = next[prev+1];

                current[prev+1] = max(include, exclude);
            }
            next = current;
        }
        return next[0];
    }

    
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
        
    //     // sort(envelopes.begin(), envelopes.end());
    //     int curr = 0;
    //     int prev = -1;
    //     int n = envelopes.size();
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    //     // return recursion(envelopes, curr, prev, dp);

    //     // return tabulation(envelopes);
    //     // return SO(envelopes);
    //     return bs(envelopes);
    // }
};