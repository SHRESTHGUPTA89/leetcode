class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // If there are no intervals, return 0
        if (intervals.empty()) return 0;

        // Sort intervals based on their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        // Initialize the end time of the first interval
        int prevEnd = intervals[0][1];

        // Start from the second interval
        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval starts before the previous interval ends, it's overlapping
            if (intervals[i][0] < prevEnd) {
                count++; // We need to remove this interval
            } else {
                // Otherwise, update the previous interval's end time
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
