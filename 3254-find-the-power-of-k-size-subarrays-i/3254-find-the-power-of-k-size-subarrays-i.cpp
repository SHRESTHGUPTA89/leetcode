class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            bool isConsecutive = true;
            int maxElement = nums[i];

            // Check if the elements in the subarray are consecutive
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isConsecutive = false;
                    break;
                }
                maxElement = max(maxElement, nums[j + 1]);
            }

            // Append the maximum element if consecutive, else append -1
            if (isConsecutive) {
                ans.push_back(maxElement);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
