class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Step 1: Sort the intervals based on their end point
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Sort by end value
        });
        
        // Step 2: Initialize arrow count and position of first arrow
        int arrows = 1;  // We need at least one arrow initially
        int arrowPosition = points[0][1];  // Shoot the first arrow at the end of the first interval
        
        // Step 3: Traverse through the balloons (intervals)
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the last shot arrow, we need a new arrow
            if (points[i][0] > arrowPosition) {
                arrows++;
                arrowPosition = points[i][1];  // Shoot a new arrow at the end of the current interval
            }
        }
        
        return arrows;  // Return the minimum number of arrows required
    }
};
