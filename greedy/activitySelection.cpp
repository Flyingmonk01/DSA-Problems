// Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.




static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        int count = 1;
        vector< pair<int, int>> act;
        for(int i = 0; i < n; i++){
            act.push_back({start[i], end[i]});
        }
        
        sort(act.begin(), act.end(), cmp);
        
        
        int curr = act[0].second;
        
        for(int i = 1; i < n; i++){
            if(act[i].first > curr){
                count++;
                curr = act[i].second;
            }
        }
        
        return count;
    }