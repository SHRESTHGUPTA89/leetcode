class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // Initialize DP array
        int maxi = 1; // To store the length of the LIS

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]); // Update the maximum length
        }

        return maxi;
    }
};
