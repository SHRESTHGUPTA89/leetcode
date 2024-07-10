#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int count = 0;
        int maxi = 0;

        while (r < n) {
            if (nums[r] == 0) {
                count++;
            }

            while (count > k) {
                if (nums[l] == 0) {
                    count--;
                }
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};
