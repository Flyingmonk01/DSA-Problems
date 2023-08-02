// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i < n-m; i++){
            for(int j = 0; j < m; j++){
                if(haystack[i+j] != needle[j]) break;
                if(j == m-1) return i;
            }
        }
        return -1;
    }