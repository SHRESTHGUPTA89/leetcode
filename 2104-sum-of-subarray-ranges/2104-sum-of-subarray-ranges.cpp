class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;  // Use long long to avoid overflow for large sums

        for (int i = 0; i < n; i++) {
            int maxx = nums[i];
            int minn = nums[i];

            for (int j = i; j < n; j++) {
                // Update maxx and minn with the current element nums[j]
                maxx = max(maxx, nums[j]);
                minn = min(minn, nums[j]);

                // Calculate the range and add to sum
                sum += (maxx - minn);
            }
        }

        return sum;
    }
};
