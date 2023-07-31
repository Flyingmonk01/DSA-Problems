// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.



bool isPossible(int k, vector<int>& stalls, int sol){
        int pos = stalls[0];
        int c = 1;
        
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - pos >= sol){
                c++;
                pos = stalls[i];
            }
            if(c == k) return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int e = stalls[stalls.size()-1] - stalls[0];
        
        int ans = -1;
        while(s <= e){
            int mid = (s + e) >> 1;
            
            if(isPossible(k, stalls, mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }