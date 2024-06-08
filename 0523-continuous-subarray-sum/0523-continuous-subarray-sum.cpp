#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        std::unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1; // To handle the case where a valid subarray starts from index 0
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;

            if (remainderIndex.find(remainder) != remainderIndex.end()) {
                if (i - remainderIndex[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndex[remainder] = i;
            }
        }

        return false;
    }
};
