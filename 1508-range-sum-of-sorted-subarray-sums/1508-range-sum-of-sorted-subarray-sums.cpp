#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        std::vector<int> subarraySums;
        const int MOD = 1000000007;

        // Generate all subarray sums using only two loops
        for (int start = 0; start < n; ++start) {
            int currentSum = 0;
            for (int end = start; end < n; ++end) {
                currentSum += nums[end];
                subarraySums.push_back(currentSum);
            }
        }

        // Sort the subarray sums
        std::sort(subarraySums.begin(), subarraySums.end());

        // Calculate the sum of elements from left to right (1-based index)
        int sum = 0;
        for (int i = left - 1; i < right; ++i) {
            sum = (sum + subarraySums[i]) % MOD;
        }

        return sum;
    }
};