class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: No prices available

        // State variables
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for (int price : prices) {
            // Update the states step-by-step
            firstBuy = max(firstBuy, -price);              // Max profit after first buy
            firstSell = max(firstSell, firstBuy + price);  // Max profit after first sell
            secondBuy = max(secondBuy, firstSell - price); // Max profit after second buy
            secondSell = max(secondSell, secondBuy + price); // Max profit after second sell
        }

        return secondSell; // Maximum profit with at most two transactions
    }
};
