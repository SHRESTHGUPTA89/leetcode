class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long currentSum = 0;
        int n = nums.size();
        unordered_set<int> elements;
        int left = 0;

        for (int right = 0; right < n; ++right) {
        
            while (elements.count(nums[right])) {
        
                elements.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }

            elements.insert(nums[right]);
            currentSum += nums[right];

        
            if (right - left + 1 == k) {
                ans = max(ans, currentSum);
        
                elements.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
        }

        return ans;
    }
};
