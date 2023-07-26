// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.


    int binary_search(vector<int>& nums, int start, int target){
        int end = nums.size()-1;
        int mid = start + (end - start)/2;

        while(start <= end){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start++;
            }
            else end--;

            mid = start + (end - start)/2;
        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        set<pair<int, int>> st;
        // while(j < nums.size()){
        //     int first = nums[i];
        //     int second = nums[j];
        //     int dif = abs(second - first);
            
        //     if(dif == k && i != j){
        //         st.insert({nums[i], nums[j]});
        //         i++;
        //         j++;
        //     }
        //     else if(dif > k){
        //         i++;
        //     }
        //     else j++;
        //     if(i == j) j++;
        // }

        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];

            if(binary_search(nums, i+1, nums[i]+k) != -1){
                st.insert({nums[i], nums[j]});
            }
        }
        return st.size();
    }