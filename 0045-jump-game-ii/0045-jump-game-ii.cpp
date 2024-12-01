class Solution {
public:
    int helper(vector<int>& nums, int index, vector<int>& memo) {
        int n = nums.size();

        // If we've reached the last index, no more jumps are needed.
        if (index >= n - 1) {
            return 0;
        }

        // If already computed, return the result.
        if (memo[index] != -1) {
            return memo[index];
        }

        int minJumps = INT_MAX;
        int maxReach = min(index + nums[index], n - 1);

        // Try all possible jumps from the current position.
        for (int next = index + 1; next <= maxReach; ++next) {
            int jumps = helper(nums, next, memo);
            if (jumps != INT_MAX) {
                minJumps = min(minJumps, jumps + 1);
            }
        }

        // Store and return the result for the current index.
        return memo[index] = minJumps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return helper(nums, 0, memo);
    }
};
