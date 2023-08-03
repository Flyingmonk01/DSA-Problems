// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.



static bool cmp(string& a, string& b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> store;
        for(int i = 0; i < nums.size(); i++){
            string temp = to_string(nums[i]);
            store.push_back(temp);
        }
        sort(store.begin(), store.end(), cmp);
        
        string ans = "";
        if(store[0] == "0") return "0";
        for(auto x:store){
            ans += x;
        }
        return ans;
    }