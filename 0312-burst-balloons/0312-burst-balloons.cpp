class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0; // Base case: no balloons to burst
        if (dp[i][j] != -1) return dp[i][j]; // Return cached result if exists

        int maxCoins = 0; // Initialize maximum coins
        for (int k = i; k <= j; k++) {
            // Coins from bursting balloon k last in the range [i, j]
            int coins = nums[i - 1] * nums[k] * nums[j + 1]
                        + f(i, k - 1, nums, dp) // Coins from left subarray
                        + f(k + 1, j, nums, dp); // Coins from right subarray
            maxCoins = max(maxCoins, coins); // Take the maximum
        }

        return dp[i][j] = maxCoins; // Store result in DP table
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); // Add virtual balloon with value 1 at the start
        nums.push_back(1); // Add virtual balloon with value 1 at the end

        // DP table initialization
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        // Solve the problem for the full range of balloons
        return f(1, n, nums, dp);
    }
};
