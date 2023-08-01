
// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.


string reverseOnlyLetters(string s) {
        int st = 0;
        int e = s.size()-1;
        while(st <= e){
            int x = s[st];
            int y = s[e];
            if(x >= 33 && x <= 64 || x >= 91 && x <= 96) st++;
            else if(y >= 33 && y <= 64 || y >= 91 && y <= 96) e--;
            else swap(s[st++], s[e--]);
        }
        return s;
    }