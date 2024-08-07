#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            int nextGreater = -1; // Default value if no greater element is found
            bool found = false; // Flag to indicate if nums1[i] has been found in nums2

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    found = true;
                }
                if (found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
