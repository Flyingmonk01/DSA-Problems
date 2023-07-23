// You are given an array A of integers of length N. You need to calculate factorial of each number. The answer can be very large, so print it modulo 109 + 7.


long long mod = 1e9+7;
    
    vector<long long> factorial(vector<long long> a, int n) {
        vector<long long> ans;
        int maxi = *max_element(a.begin(), a.end());
        
        vector<long long> fact(maxi+1);
        fact[1] = 1;
        for(int i = 2; i <= maxi; i++){
            fact[i] = (fact[i-1]*i)%mod;
        }
        
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                ans.push_back(1);
            }
            else ans.push_back(fact[a[i]]);
        }
        return ans;
    }