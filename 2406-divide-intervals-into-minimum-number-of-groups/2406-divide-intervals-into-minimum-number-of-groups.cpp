class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> startTimes, endTimes;
        
    
        for (auto &interval : intervals) {
            startTimes.push_back(interval[0]);
            endTimes.push_back(interval[1]);
        }
        
    
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int n = intervals.size();
        int activeGroups = 0, maxGroups = 0;
        int i = 0, j = 0;
        
        
        while (i < n) {
            if (startTimes[i] <= endTimes[j]) {
                
                activeGroups++;
                maxGroups = max(maxGroups, activeGroups);
                i++;
            } else {
                
                activeGroups--;
                j++;
            }
        }
        
        return maxGroups;
    }
};


        