// Given an integer N, find its factorial. return a list of integers denoting the digits that make up the factorial of N.



vector<int> factorial(int N){
        // code here
        int carry = 0;
        vector<int> ans;
        ans.push_back(1);
        
        for(int i = 2; i <= N; i++){
            
            for(int j = 0; j < ans.size(); j++){
                int num = ans[j]*i + carry;
                ans[j] = num%10;
                carry = num/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry /= 10;
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }