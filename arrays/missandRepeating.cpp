// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.



vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<int> ans;
        
        int rep = 0;
                
        int miss = -1;
        for(int i = 0; i < n; i++){
            int index = abs(arr[i]);
            if(arr[index-1] > 0){
                arr[index-1] *= -1;
            }
            else rep = abs(arr[i]);
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] > 0)
                miss = i+1;
        }
        
        
        ans.push_back(rep);
        ans.push_back(miss);
        
        return ans;
    }