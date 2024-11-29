class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: No prices available

        // State variables
        int held = INT_MIN;    // Maximum profit while holding a stock
        int sold = 0;          // Maximum profit after selling a stock
        int cooldown = 0;      // Maximum profit during cooldown

        for (int price : prices) {
            int prevSold = sold; // Store the previous sold state

            // Update the states step-by-step
            sold = held + price;             // Sell the stock today
            held = max(held, cooldown - price); // Buy the stock today or keep holding
            cooldown = max(cooldown, prevSold); // Enter cooldown or stay in cooldown
        }

        // Maximum profit is the maximum of sold or cooldown state
        return max(sold, cooldown);
    }
};
