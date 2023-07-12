// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common sint getLongestCommonSubstr(string& s1, int& n, int i, string& s2, int& m, int j, vector<vector<int>>& dp){
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
            dp[i][j] = 1 + getLongestCommonSubstr(s1, n, i+1, s2, m, j+1, dp);
        }
        else{
            dp[i][j] = max(getLongestCommonSubstr(s1, n, i, s2, m, j+1, dp), getLongestCommonSubstr(s1, n, i+1, s2, m, j, dp));
        }
        return dp[i][j];
    }

    int getLongestCommonSubstrTab(string& s1, string& s2){
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp (n+1, vector<int>(m+1, 0));
        // dp[0][0] = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
    
    int getLongestCommonSubstrSO(string& s1, string& s2){
        int n = s1.length();
        int m = s2.length();

        vector<int> curr(m+1, 0), prev(m+1, 0);


        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(curr[j+1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp (n+1, vector<int>(m+1, -1));
        return getLongestCommonSubstrSO(text1, text2);
    }ubsequence of two strings is a subsequence that is common to both strings.


