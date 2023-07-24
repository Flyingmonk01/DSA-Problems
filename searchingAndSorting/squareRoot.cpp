// Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).



long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        if(x == 1){
            return 1;
        }
        long long int s = 1;
        long long int e = x/2;
        long long int mid = s + (e-s)/2;
        long long int ans = -1;
        while(s <= e){
            long long int element = mid*mid;
            
            if(element <= x){
                ans = mid;
                s = mid+1;
            }
            else if(element > x){
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }