class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);  // Initialize all answers to -1
        
        // Loop through each interval to find the right interval
        for (int i = 0; i < n; ++i) {
            int minStart = INT_MAX;
            int rightIntervalIndex = -1;
            
            // Compare the current interval with every other interval
            for (int j = 0; j < n; ++j) {
                // We need to find an interval whose start >= end of the current interval
                if (intervals[j][0] >= intervals[i][1]) {
                    if (intervals[j][0] < minStart) {
                        minStart = intervals[j][0];  // Track the smallest start time
                        rightIntervalIndex = j;  // Track the index of this interval
                    }
                }
            }
            
            // Store the index of the right interval (if found)
            ans[i] = rightIntervalIndex;
        }
        
        return ans;
    }
};
