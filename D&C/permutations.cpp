// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.



void solve(string& s,  vector<string>& ans, int idx){
	        if(idx >= s.length()){
	            ans.push_back(s);
	            return;
	        }
	        
	        for(int i = idx; i < s.length(); i++){
	            swap(s[i], s[idx]);
	            solve(s, ans, idx+1);
	            swap(s[i], s[idx]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
            set<string> st;
		    vector<string> ans;
		    int idx = 0;
		    solve(S, ans, idx);
		    for(auto x: ans){
		        st.insert(x);
		    }
		    ans.clear();
		    for(auto X : st){
		        ans.push_back(X);
		    }
		    return ans;
		}