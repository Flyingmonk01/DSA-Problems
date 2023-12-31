// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.


long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        sort(a.begin(), a.end());
        
        int start = 0;
        int end = m-1;
        
        int minDiff = INT_MAX;
        while(end < n){
            int diff = a[end]-a[start];
            minDiff = min(minDiff, diff);
            start++;
            end++;
        }
        return minDiff;
    } 