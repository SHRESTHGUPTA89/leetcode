class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Since the max possible location is not given, we can safely assume some large enough size
        vector<int> stops(1001, 0); // Let's assume maximum location is 1000

        // Update the passengers count at each stop
        for (auto &t : trips) {
            int numPassengers = t[0];
            int startLocation = t[1];
            int endLocation = t[2];
            
            stops[startLocation] += numPassengers;   // Add passengers at start location
            stops[endLocation] -= numPassengers;     // Remove passengers at end location
        }
        
        // Check the total number of passengers at each location
        int currentPassengers = 0;
        for (int i = 0; i < 1001; ++i) {
            currentPassengers += stops[i];  // Update current passengers at location `i`
            if (currentPassengers > capacity) {
                return false;  // Capacity exceeded
            }
        }
        
        return true;  // All trips can be completed within the given capacity
    }
};
