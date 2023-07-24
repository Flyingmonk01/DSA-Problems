int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int sumN = n*(n+1)/2;
        // int sumA = 0;
        // for(int i = 0; i < n; i++){
        //     sumA += nums[i];
        // }
        // return sumN-sumA;
        int Xor = 0;
        for(int i = 0; i < nums.size(); i++){
            Xor ^= nums[i] ^ i+1;
        }
        
        return Xor;
    }