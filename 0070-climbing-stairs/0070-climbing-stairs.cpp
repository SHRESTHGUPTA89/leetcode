class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        // Initialize the dp vector with size n+1 (to include index n) and default values of 0
        vector<int> dp(n + 1);
        
        // Base cases
        dp[1] = 1;
        dp[2] = 2;
        
        // Fill the dp table for all steps from 3 to n
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        // Return the number of ways to climb n stairs
        return dp[n];
    }
};
