// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.


void remove(string& s, string& part){
        int idx = s.find(part);
        if(idx != string::npos){
            string leftS = s.substr(0, idx);
            string rightS = s.substr(idx+part.size(), INT_MAX);
            s = leftS + rightS;
            remove(s, part);
        }
    }
    
    string removeOccurrences(string s, string part) {
        remove(s, part);
        return s;
    }