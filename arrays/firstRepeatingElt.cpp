// Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 


int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int, int> map;
        
        for(int i = 0; i < n; i++){
            // if(map[arr[i]] == 0){
                map[arr[i]] = i+1;
            // }
        }
        
        for(int i = 0; i < n; i++){
            
            if(map[arr[i]] != i+1){
                return i+1;
            }   
            continue;   
        }
        
        return -1;
    }