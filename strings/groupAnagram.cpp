// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



std::array<int, 256> hashed(string& s){
        std::array<int, 256> hash = {0};
        for(int i = 0; i < s.size(); i++){
            hash[s[i]] ++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int, 256>, vector<string>> map;

        for(auto s:strs){
            map[hashed(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(auto s:strs){
            string x = s;
            sort(x.begin(), x.end());
            map[x].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }

