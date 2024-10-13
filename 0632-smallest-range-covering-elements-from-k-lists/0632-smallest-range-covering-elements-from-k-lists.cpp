class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> vec(k, 0);  // Keeps track of the index of each list
        vector<int> ans = {-1000000, 1000000};
        
        while (true) {
            int minEl = INT_MAX;
            int maxEl = INT_MIN;
            int minElLastIdx = 0;
            
            // Find the minimum and maximum element in the current range
            for (int i = 0; i < k; i++) {
                int listIdx = i;
                int elIdx = vec[i];
                int element = nums[listIdx][elIdx];
                
                if (element < minEl) {
                    minEl = element;
                    minElLastIdx = listIdx;
                }
                maxEl = max(maxEl, element);
            }
            
            // Update the answer if we found a smaller range
            if (maxEl - minEl < ans[1] - ans[0]) {
                ans[0] = minEl;
                ans[1] = maxEl;
            }
            
            // Move to the next element in the list that had the minimum element
            int nextIdx = vec[minElLastIdx] + 1;
            if (nextIdx >= nums[minElLastIdx].size()) {
                break;  // If any list is exhausted, we are done
            }
            vec[minElLastIdx] = nextIdx;
        }
        
        return ans;
    }
};
