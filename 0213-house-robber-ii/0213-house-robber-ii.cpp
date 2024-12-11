class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start]; // Only one house to rob
        
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(nums[start + i] + dp[i - 2], dp[i - 1]);
        }
        
        return dp[dp.size() - 1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // No houses to rob
        if (n == 1) return nums[0]; // Only one house to rob
        
        // Case 1: Rob houses from 0 to n-2
        int case1 = robLinear(nums, 0, n - 2);
        
        // Case 2: Rob houses from 1 to n-1
        int case2 = robLinear(nums, 1, n - 1);
        
        // The maximum of the two cases
        return max(case1, case2);
    }
};

