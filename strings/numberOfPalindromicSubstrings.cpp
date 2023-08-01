// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.




int expandIdx(string& str, int s, int e){
        int count = 0;
        while(s >= 0 && e < str.length() && str[s] == str[e]){
            s--;
            e++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            int oddLength = expandIdx(s, i, i);
            count += oddLength;
            int evenLength = expandIdx(s, i, i+1);
            count += evenLength;
        }
        return count;
    }