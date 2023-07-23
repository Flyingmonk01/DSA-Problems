// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.



vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while(i < nums.size()){
            int index = nums[i]-1;
            if(nums[i] != nums[index])
                swap(nums[i], nums[index]);
            else i++;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }