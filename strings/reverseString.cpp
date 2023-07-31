// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.



void helper(vector<char>& st, int s, int e){
        if(s >= e) return;
        swap(st[s], st[e]);
        s++; e--;
        helper(st, s, e);
    }
    void reverseString(vector<char>& st) {
        int s = 0; int e = st.size()-1;
        helper(st, s, e);
        
    }