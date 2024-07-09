#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            // Ensure nums[i] is within the valid range [1, n]
            if (nums[i] > 0 && nums[i] <= n) {
                int correct = nums[i] - 1;

                // Swap if nums[i] is not in the correct position
                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        // Find the first index where the number is not the index + 1
        for (int j = 0; j < n; j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }

        // If all numbers are in the correct place, return n + 1
        return n + 1;
    }
};

