// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 
 bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        for(int i = 0; i < s.length(); i++){
            if(mp1[s[i]]!= 0 && mp1[s[i]] != t[i]){
                return false;
            }
            if(mp2[t[i]] != 0 && mp2[t[i]] != s[i]){
                return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }