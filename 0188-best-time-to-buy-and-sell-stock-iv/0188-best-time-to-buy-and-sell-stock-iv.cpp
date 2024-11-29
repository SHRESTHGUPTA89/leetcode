class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0; // Edge case: No prices or no transactions allowed

        // If k >= n/2, it is effectively unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }

        // Create arrays to store maximum profits for each transaction
        vector<int> buy(k + 1, INT_MIN);  // Max profit after buying for the ith transaction
        vector<int> sell(k + 1, 0);      // Max profit after selling for the ith transaction

        for (int price : prices) {
            for (int t = 1; t <= k; ++t) {
                buy[t] = max(buy[t], sell[t - 1] - price);  // Buy at current price
                sell[t] = max(sell[t], buy[t] + price);     // Sell at current price
            }
        }

        return sell[k]; // Maximum profit after at most k transactions
    }
};
