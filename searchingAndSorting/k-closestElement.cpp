// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b



vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int &a, int &b){
            if(abs(x-a) < abs(x-b)) return true;
            else if (abs(x-a) == abs(x-b)) return a<b;
            else return false;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i]); 
        }
        sort(ans.begin(), ans.end());
        return ans;
    }





// 2 Way
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high-low >= k){
            if(x-arr[low] > arr[high]-x){
                low++;
            }
            else if(x-arr[low] <= arr[high] -x){
                high--;
            }
        }
        vector<int> ans;
        for(int i = low; i <= high; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }