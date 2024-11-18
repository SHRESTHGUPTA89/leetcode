class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the input to handle duplicates
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int N = 1 << n; // Total subsets (2^n)
        set<vector<int>> uniqueSubsets; // Use set to avoid duplicates
        
        for (int i = 0; i < N; i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    subset.push_back(nums[j]);
                }
            }
            uniqueSubsets.insert(subset); // Add subset to set
        }
        
        // Convert set back to vector
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
    }
};
