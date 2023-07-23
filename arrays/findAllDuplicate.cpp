// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.


vector<int> findDuplicates(vector<int>& nums) {
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
                ans.push_back(nums[i]);
            }
            cout << nums[i] << " ";
        }
        return ans;
    }