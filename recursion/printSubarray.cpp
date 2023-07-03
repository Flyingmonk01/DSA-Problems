// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.



void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int idx){
        if(idx >= nums.size()) return;

        temp.push_back(nums[idx]);
        ans.push_back(temp);
        helper(nums, temp, ans, idx+1);
        temp.pop_back();
        helper(nums, temp, ans, idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {            
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back({});
        helper(nums, temp, ans, 0);
        return ans;
    }