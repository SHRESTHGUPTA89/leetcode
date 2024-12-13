class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        
        map<int, vector<int>> valueToIndices;
        for (int i = 0; i < nums.size(); i++) {
            valueToIndices[nums[i]].push_back(i);
        }

        
        vector<bool> visited(nums.size(), false);

        
        for (const auto& [value, indices] : valueToIndices) {
            for (int index : indices) {
                if (!visited[index]) {
                    // Add to score and mark this element and neighbors as visited
                    score += value;
                    visited[index] = true;

                    // Mark neighbors
                    if (index > 0) visited[index - 1] = true;
                    if (index < nums.size() - 1) visited[index + 1] = true;
                }
            }
        }

        return score;
    }
};
