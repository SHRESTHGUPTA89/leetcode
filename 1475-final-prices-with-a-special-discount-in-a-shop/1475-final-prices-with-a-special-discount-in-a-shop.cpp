class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(prices); // Initialize `ans` with original prices
        stack<int> st;           // Monotonic decreasing stack to store indices

        for (int i = 0; i < n; i++) {
            // Check for a discount for indices in the stack
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] -= prices[i]; // Apply discount
                st.pop();                   // Remove index after applying discount
            }
            st.push(i); // Push the current index onto the stack
        }

        return ans;
    }
};
