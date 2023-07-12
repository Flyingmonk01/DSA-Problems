// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

 int helper(string& s, string& rev){
        int n = s.length();
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == rev[j]){
                    curr[j] = 1 + next[j+1];
                }
                else{
                    curr[j] = max(curr[j+1], next[j]);
                }
            }
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        string rev_str = "";
        for(int i = s.length()-1; i >= 0; i--){
            rev_str += s[i];
        }
        // cout << rev_str << endl;
        return helper(s, rev_str);
    }