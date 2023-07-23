// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.


int findDuplicate(vector<int>& arr) {
        // int ans = 0;
        // for(int i = 0; i < arr.size(); i++){
        //     ans ^= arr[i];
        //     ans ^= i;
        // }
        
        // return ans;


        // int ans = -1;
        // for(int i = 0; i < arr.size(); i++){
        //     int index = abs(arr[i]);
        //     if(arr[index] < 0){
        //         ans = index;
        //         break;
        //     }

        //     arr[index] *= -1;

        // }
        // return ans;


        while(arr[0] != arr[arr[0]]){
            swap(arr[0], arr[arr[0]]);
        }
        return arr[0];
    }