// Q. Given a string S  and a character X, the task is to find the last index (0 based indexing) of X in string S. If no index found then the answer will be -1.

int helper(string& s, int idx, char& p){
        if(idx < 0) return -1;
        
        if(s[idx] == p){
            return idx;
        }
        return helper(s, idx-1, p);
    }
    
    int LastIndex(string s, char p){
        //complete the function here
        
        int idx = s.size()-1;
        return helper(s, idx, p);
    }