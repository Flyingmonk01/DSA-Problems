
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

 int getPivot(vector<int>& nums, int size){
        int s = 0;
        int e = size-1;
        int mid = s + (e-s)/2;
        while(s < e){
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }

    int bs(vector<int>& nums, int t, int s, int e){
        int ans = -1;
        int mid = s + (e-s) / 2;
        while(s <= e){
            if(nums[mid] == t){
                ans = mid;
                break;
            }
            else if(nums[mid] < t){
                s = mid+1;
            }
            else if(nums[mid] > t){
                e = mid-1;
            }
            mid = s + (e-s) / 2;
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        // int pivot = getPivot(nums, nums.size());

        // if(target >= nums[pivot] && target <= nums[nums.size()-1]){
        //     return bs(nums, target, pivot, nums.size()-1);
        // }
        // else{
        //     return bs(nums, target, 0, pivot);
        // }


        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e){
            int mid = (s+e) >> 1;

            if(nums[mid] == target) return mid;

            // if(nums[mid] == nums[s] && nums[mid] == nums[e]){
            //     s++, e--;
            //     continue;
            // }
            if(nums[s] <= nums[mid]){
                if(nums[s] <= target && target <= nums[mid]){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && target <= nums[e]){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return -1;
    }