class Solution {
public:
    int minDistance(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Step 1: Build the DP table to find the LCS length
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Length of the LCS
        int lcsLength = dp[m][n];

        // Step 2: Calculate minimum number of operations
        int deletions = m - lcsLength;
        int insertions = n - lcsLength;

        return deletions + insertions;
    }
};
