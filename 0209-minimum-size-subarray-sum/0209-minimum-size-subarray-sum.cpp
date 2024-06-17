#include <algorithm>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLength = n + 1;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLength = std::min(minLength, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }

        return (minLength == n + 1) ? 0 : minLength;
    }
};
