// Given an unsorted array arr[] of size N having both negative and positive integers. The task is place all negative element at the end of array without changing the order of positive element and negative element.


void segregateElements(int arr[],int n)
    {
        int result[n] = {0};
        int idx = 0;
        
        for(int i = 0; i < n; i++){
            result[i] = arr[i];
        }
        
        
        for(int i = 0; i < n; i++){
            if(result[i] >= 0){
                arr[idx] = result[i]; 
                idx++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(result[i] < 0){
                arr[idx] = result[i];
                idx++;
            }
        }

    }


    