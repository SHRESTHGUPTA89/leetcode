class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals. First by start time, and if same start, by end time (in descending order)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];  // Sort by end in descending order if start is the same
            }
            return a[0] < b[0];  // Otherwise, sort by start in ascending order
        });
        
        int remaining = 0;
        int maxEnd = 0;
        
        // Step 2: Iterate over the sorted intervals
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            // If the current interval is not covered by the previous one
            if (end > maxEnd) {
                remaining++;  // Count this interval
                maxEnd = end;  // Update maxEnd to this interval's end
            }
            // If the current interval is covered by the previous one, we skip it
        }
        
        return remaining;
    }
};
