// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order



void solve(int num, int n, int k, vector<vector<int>>& ans, vector<int>& temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        for(int i = num; i <= n; i++){
            temp.push_back(i);
            solve(i+1, n, k, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, k, ans, temp);
        return ans;
    }