
// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.



bool isPossible(int arr[], int n, int k, long long sol){
        long long paintSum = 0;
        int c = 1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > sol){
                return false;
            }
            
            if(arr[i] + paintSum > sol){
                c++;
                paintSum = 0;
                paintSum = arr[i];
                if(c > k){
                    return false;
                }
            }
            else{
                paintSum += arr[i];
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        
        long long start = 0;
        long long end = 0;
        for(int i = 0; i < n; i++){
            end += arr[i];
        }

        long long ans = -1;
        long long mid = start + (end-start)/2;
        
        while(start <= end){
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }