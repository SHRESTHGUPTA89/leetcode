class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n + 1, vector<int>(amount + 1, INT_MAX)); 

        // Initialize the DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0) {
                    t[i][j] = 0; // Amount is 0, 0 coins are required
                }
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    if (t[i][j - coins[i - 1]] != INT_MAX) {
                        t[i][j] = min(t[i][j - coins[i - 1]] + 1, t[i - 1][j]);
                    } else {
                        t[i][j] = t[i - 1][j];
                    }
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][amount] == INT_MAX ? -1 : t[n][amount]; // If the amount is unreachable, return -1
    }
};
