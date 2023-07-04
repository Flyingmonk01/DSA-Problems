// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).


bool helper(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        // base case
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // match case
        if(p[j] == '?' || s[i] == p[j]){
            return dp[i][j] = helper(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*'){
            return dp[i][j] = helper(s, p, i-1, j, dp) || helper(s, p ,i ,j-1, dp);
        }
        else return false;
        
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return helper(s, p, s.size()-1, p.size()-1, dp);
    }