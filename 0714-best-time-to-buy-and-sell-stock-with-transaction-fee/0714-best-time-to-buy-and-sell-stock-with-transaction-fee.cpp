class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: No prices available

        long long held = -prices[0]; // Start as if the stock is bought on the first day
        long long sold = 0;          // No profit initially

        for (int i = 1; i < n; ++i) {
            long long prevSold = sold; // Store the previous sold state

            // Update the states
            sold = max(sold, held + prices[i] - fee); // Sell the stock and pay the fee
            held = max(held, prevSold - prices[i]);  // Buy the stock or keep holding
        }

        // Maximum profit is in the "sold" state
        return static_cast<int>(sold); // Convert result back to int
    }
};
