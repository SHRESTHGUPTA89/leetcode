class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // No houses to rob
        if (n == 1) return nums[0]; // Only one house
        
        
        int prev = 0; // Max money robbed from house i-2
        int curr = 0; // Max money robbed from house i-1
        
        for (int num : nums) {
            int current = max(num + prev, curr); // Max money if robbing this house
            prev = curr; // Update prev2 to the previous house's max
            curr = current; // Update prev1 to the current house's max
        }
        
        return curr; // The last value in prev1 is the answer
    }
};
