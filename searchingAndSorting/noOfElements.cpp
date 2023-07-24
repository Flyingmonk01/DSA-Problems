// Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.


int count(int arr[], int n, int x) {
	    // code here
	    int first = -1;
	    int last = -1;
	    
	    int s = 0;
	    int e = n-1;
	    int mid = s + (e-s)/2;
	    while(s <= e){
	        if(arr[mid] == x){
	            first = mid;
	            e = mid-1;
	        }
	        else if(arr[mid] < x){
	            s = mid+1;
	        }
	        else e = mid-1;
	        
	        mid = s + (e-s)/2;
	    }
	    s = 0;
	    e = n-1;
	    mid = s + (e-s)/2;
	    while(s <= e){
	        if(arr[mid] == x){
	            last = mid;
	            s = mid+1;
	        }
	        else if(arr[mid] < x){
	            s = mid+1;
	        }
	        else e = mid-1;
	        
	        mid = s + (e-s)/2;
	    }
	    if(first == -1 || last == -1) return 0;
	    return last-first+1;
	}