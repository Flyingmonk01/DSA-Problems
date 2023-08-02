// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".


string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++){
            char curr_ch = strs[0][i];
            bool match = true;

            for(int j = 1; j < strs.size(); j++){
                if(curr_ch != strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(!match){
                break;
            }
            else ans += curr_ch;
        }
        return ans;
    }