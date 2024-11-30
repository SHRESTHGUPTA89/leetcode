class Solution {
public:
    bool canJumpFrom(int index, vector<int>& nums, vector<int>& memo) {
        // Base case: If we reach or exceed the last index, return true
        if (index >= nums.size() - 1) {
            return true;
        }

        // If the result for this index is already computed, return it
        if (memo[index] != -1) {
            return memo[index];
        }

        // Calculate the maximum jump we can make from the current index
        int maxJump = nums[index];
        for (int jump = 1; jump <= maxJump; ++jump) {
            // Check recursively if we can reach the end from the new position
            if (canJumpFrom(index + jump, nums, memo)) {
                return memo[index] = true; // Store result and return
            }
        }

        // If no jumps lead to the end, store and return false
        return memo[index] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // Initialize memoization table with -1 (uncomputed)
        vector<int> memo(n, -1);
        return canJumpFrom(0, nums, memo);
    }
};
