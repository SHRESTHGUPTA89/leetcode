class Solution {
public:
    long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp) {
        // Base case: No transactions possible after the last day
        if (ind == n) {
            return 0;
        }

        // Return cached result if already computed
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        long profit = 0;

        if (buy == 0) { // Can buy the stock
            profit = max(
                0 + getAns(Arr, ind + 1, 0, n, dp),       // Skip buying
                -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp) // Buy the stock
            );
        } else { // Can sell the stock
            profit = max(
                0 + getAns(Arr, ind + 1, 1, n, dp),       // Skip selling
                Arr[ind] + getAns(Arr, ind + 1, 0, n, dp)  // Sell the stock
            );
        }

        // Cache and return the computed profit
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: No prices

        // Convert prices to a long array
        vector<long> pricesLong(prices.begin(), prices.end());

        // DP table for memoization
        vector<vector<long>> dp(n, vector<long>(2, -1));

        // Compute maximum profit starting from day 0 with "can buy" state
        long ans = getAns(&pricesLong[0], 0, 0, n, dp);
        return ans;
    }
};
