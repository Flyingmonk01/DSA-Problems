// An array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.



int peakIndexInMountainArray(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int mid = s + (e - s)/2;
        while(s < e){
            if(nums[mid] < nums[mid+1]) s = mid+1;
            else e = mid;
            mid = s + (e-s)/2;
        }
        return mid;
    }