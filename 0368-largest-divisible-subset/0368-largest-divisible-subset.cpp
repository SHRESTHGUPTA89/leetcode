#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

    
        sort(nums.begin(), nums.end());

        
        vector<int> dp(n, 1);   // DP to store the size of the largest subset ending at each index
        vector<int> hash(n, -1); // Hash table to reconstruct the subset

        int maxi = 1; // Maximum subset length
        int lastIndex = 0; // Index of the last element in the largest subset

        // Step 3: Fill the DP and hash arrays
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j; // Record the previous index
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i; // Update the index of the last element
            }
        }

        // Step 4: Reconstruct the subset
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }

        // Step 5: Reverse the result to get it in ascending order
        reverse(result.begin(), result.end());

        return result;
    }
};
