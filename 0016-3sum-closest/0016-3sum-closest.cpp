class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort the array
        
        int ans = nums[0] + nums[1] + nums[2];  // Initialize with the sum of the first three elements
        
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                // Update ans if this sum is closer to the target
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }
                
                // Move the pointers based on comparison with the target
                if (sum < target) {
                    j++;  // Try to increase the sum
                } else if (sum > target) {
                    k--;  // Try to decrease the sum
                } else {
                    // If sum == target, this is the closest possible result, so return it
                    return sum;
                }
            }
        }
        
        return ans;  // Return the closest sum found
    }
};
