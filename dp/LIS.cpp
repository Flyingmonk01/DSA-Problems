// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .



class Solution {
public:

    int recursion(vector<int>& nums, int idx, int pre){
        if(idx >= nums.size()) return 0;

        // include
        int include = 0;
        if(pre == -1 || nums[pre] < nums[idx]){
            include = 1 + recursion(nums, idx+1, idx);
        }
        int exclude = recursion(nums, idx+1, pre);
        return max(include, exclude);
    }

    int memoization(vector<int>& nums, int idx, int pre, vector<vector<int>>& dp){
        if(idx >= nums.size()) return 0;

        if(dp[idx][pre+1] != -1) return dp[idx][pre+1];
        // include
        int include = 0;
        if(pre == -1 || nums[pre] < nums[idx]){
            include = 1 + memoization(nums, idx+1, idx, dp);
        }
        int exclude = memoization(nums, idx+1, pre, dp);
        return dp[idx][pre+1] = max(include, exclude);
    }


    int tabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int idx = nums.size()-1; idx >= 0; idx--){
            for(int pre = idx-1; pre >= -1; pre--){
                int include = 0;
                if(pre == -1 || nums[pre] < nums[idx]){
                    include = 1 + dp[idx+1][idx+1];
                }
                int exclude =dp[idx+1][pre+1];
                dp[idx][pre+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int SO(vector<int>& nums){
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int idx = nums.size()-1; idx >= 0; idx--){
            for(int pre = idx-1; pre >= -1; pre--){
                int include = 0;
                if(pre == -1 || nums[pre] < nums[idx]){
                    include = 1 + next[idx+1];
                }
                int exclude =next[pre+1];
                curr[pre+1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        // vector<int> ans;
        // ans.push_back(nums[0]);
        // for(int i=1; i<nums.size(); i++)
        // {
        //     if(nums[i]>ans.back())
        //     {
        //         ans.push_back(nums[i]);
        //     }
        //     else
        //     {
        //         int index=lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
        //         ans[index]=nums[i];
        //     }
        // }    
        // return ans.size();

        int prev = -1;
        int index = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return memoization(nums, index, prev, dp);

        // return tabulation(nums);
        return SO(nums);

    }
};