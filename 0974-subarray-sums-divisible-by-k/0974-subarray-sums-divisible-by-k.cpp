#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;  // To handle the case when a subarray itself is divisible by k.
        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            // Adjust for negative remainders
            if (remainder < 0) remainder += k;

            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return count;
    }
};

      