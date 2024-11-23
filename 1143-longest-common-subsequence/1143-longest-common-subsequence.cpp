// T.C: O(m*n)
// S.C: O(m*n)
// Approach-2 (Bottom-Up Dynamic Programming)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // Create a DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Build the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Return the value in the bottom-right cell of the table
        return dp[m][n];
    }
};
