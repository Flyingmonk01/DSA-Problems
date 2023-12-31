// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character




class Solution {
public:

    int recursion(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(a.length() == i){
            return b.length()-j;
        }
        if(b.length() == j){
            return a.length()-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(a[i] == b[j]){
            ans = recursion(a, b, i+1, j+1, dp);
        }
        else{
            int insert = 1 + recursion(a, b, i, j+1, dp);
            int deleted = 1 + recursion(a, b, i+1, j, dp);
            int replace = 1 + recursion(a, b, i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        return dp[i][j] = ans;
    }

    int tabulation(string& a, string& b){
        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1, 0));
        for(int j = 0; j < b.length(); j++){
            dp[a.length()][j] = b.length()-j;
        }
        for(int i = 0; i < a.length(); i++){
            dp[i][b.length()] = a.length()-i;
        }

        for(int i = a.length()-1; i >= 0; i--){
            for(int j = b.length()-1; j >= 0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int SO(string& a, string& b){
        vector<int> curr(b.length()+1, 0); 
        vector<int> next(b.length()+1, 0);

        for(int j = 0; j <= b.length(); j++){
            next[j] = b.length()-j;
        }     
        for(int i = a.length()-1; i >= 0; i--){
            curr[b.length()] = a.length()-i;
            for(int j = b.length()-1; j >= 0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        // return recursion(word1, word2, 0, 0, dp);
        // return tabulation(word1, word2);
        return SO(word1, word2);

    }
};