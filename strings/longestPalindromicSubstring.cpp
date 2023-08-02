// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.


bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;

            i++, j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isPalindrome(s, i, j)){
                    string res = s.substr(i, j-i+1);
                    ans = res.size() > ans.size() ? res : ans;
                }
            }
        }
        return ans;
    }