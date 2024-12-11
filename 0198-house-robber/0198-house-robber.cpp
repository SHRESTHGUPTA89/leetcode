class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // No houses to rob
        if (n == 1) return nums[0]; // Only one house to rob
        
        // Create a DP array to store the maximum amount robbed up to each house
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0];               // Rob the first house
        dp[1] = max(nums[0], nums[1]); // Choose the max of robbing either the first or second house
        
        // Fill the DP array
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        
        // The last element in dp contains the maximum money that can be robbed
        return dp[n - 1];
    }
};
