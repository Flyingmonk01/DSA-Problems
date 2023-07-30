

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


void sort012(int arr[], int n)
    {
        // code here 
        int i = 0, start = 0, j = n-1;
        
        while(start <= j){
            
            if(arr[start] == 0){
                swap(arr[start++], arr[i++]);
            }
            
            else if(arr[start] == 2){
                swap(arr[start], arr[j--]);
            }
            else if(arr[start] == 1){
                start++;
            }
            
        }
    }