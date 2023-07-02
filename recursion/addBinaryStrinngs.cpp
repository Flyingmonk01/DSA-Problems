// Q. Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


string helper(string& s){
        int index = 0; string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                index = i;
                break;
            }
        }
        while(index < s.size()){
            res += s[index++];
        }
        return res;
    }
    
	string addBinary(string A, string B)
	{
	    // your code here
	    int i = A.size()-1;
	    int j = B.size()-1;
	    int carry = 0;
	    string ans = "";
	    while(i >= 0 || j >= 0 || carry){
	        if(i >= 0){
	            carry += A[i]-'0';
	            i--;
	        }
	        if(j >= 0){
	            carry += B[j] -'0';
	            j--;
	        }
	        ans += (carry%2 +'0');
	        carry = carry/2;
	    }
	    reverse(ans.begin(), ans.end());
	   return helper(ans);
	    
	}