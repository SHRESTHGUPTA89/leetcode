class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, F = 0;
        
        // Calculate the sum of the array and the initial value F(0)
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F += i * nums[i];
        }
        
        long long maxVal = F;
        
        // Use the derived relation to compute F(k+1) from F(k)
        for (int i = n - 1; i >= 1; --i) {
            F += sum - n * nums[i];
            maxVal = max(maxVal, F);
        }
        
        return maxVal;
    }
};
