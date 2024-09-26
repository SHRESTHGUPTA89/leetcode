class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        // First, insert intervals before the newInterval that don't overlap
        for (auto& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                // Non-overlapping interval that comes before newInterval
                ans.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                // Non-overlapping interval that comes after newInterval
                ans.push_back(newInterval);
                newInterval = interval;  // Update newInterval to handle subsequent intervals
            } else {
                // Overlapping intervals: merge with newInterval
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        
        // Insert the last merged interval (newInterval) if it wasn't added
        ans.push_back(newInterval);
        
        return ans;
    }
};

    
        
        
