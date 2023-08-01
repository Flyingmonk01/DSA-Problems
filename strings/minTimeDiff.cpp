// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 


int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i = 0; i < timePoints.size(); i++){
            string time = timePoints[i];
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            int total = hour*60 + minute;
            minutes.push_back(total);
        }
        sort(minutes.begin(), minutes.end());
        int mini = INT_MAX;
        for(int i = 1; i < minutes.size(); i++){
            int diff = minutes[i]-minutes[i-1];
            mini = min(mini, diff);
        }

        int lastDiff = 1440 + minutes[0] - minutes[minutes.size()-1];
        mini = min(lastDiff, mini);
        return mini;
    }