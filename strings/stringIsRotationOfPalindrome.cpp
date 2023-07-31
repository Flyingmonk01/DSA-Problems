// Given a string s, check if it can be rotated to form a palindrome.


bool isPalindrome(string& s){
        int st = 0;
        int e = s.size()-1;
        while(st <= e){
            if(s[st] != s[e]){
                return false;
            }
            st++, e--;
        }
        return true;
    }
	
	int isRotatedPalindrome(string s)
	{
	    int n = s.size();
	    if(isPalindrome(s)){
	        return 1;
	    }
	    
	    for(int i = 0; i < n; i++){
	        string first = s.substr(0, i+1);
	        string second = s.substr(i+1);
	        second.append(first);
	        if(isPalindrome(second)){
	            return 1;
	        }
	    }
	    return 0;
	}