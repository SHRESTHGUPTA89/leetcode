class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return 1;

        // Determine the maximum value in nums to define the size of the frequency array.
        int maxValue = *max_element(nums.begin(), nums.end());

        // Create a frequency array to track the range adjustments.
        vector<int> count(maxValue + k + 2, 0);

        // Update the frequency array based on the allowable range [num - k, num + k].
        for (int num : nums) {
            count[max(num - k, 0)]++;
            count[min(num + k + 1, maxValue + k + 1)]--;
        }

        // Calculate the maximum beauty using prefix sums.
        int maxBeauty = 0;
        int currentSum = 0;
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};
