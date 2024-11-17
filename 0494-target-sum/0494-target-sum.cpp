class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array
        
        // Check if the problem is feasible
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0; // Impossible to partition
        }
        
        int subsetSum = (totalSum + target) / 2; // Calculate the subset sum needed

        // Use dynamic programming to count subsets with the required sum
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));

        // Initialize the DP table
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // One way to achieve sum 0: empty subset
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= subsetSum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][subsetSum]; // Return the result
    }
};
