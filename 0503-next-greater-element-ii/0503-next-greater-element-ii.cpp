class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Initialize the answer vector with -1s
        stack<int> s;  // Stack to store indices
        
        for (int i = 0; i < 2 * n; i++) {  // Loop through the array twice
            int num = nums[i % n];  // Get the element in circular fashion
            while (!s.empty() && nums[s.top()] < num) {
                ans[s.top()] = num;  // Set the next greater element
                s.pop();  // Remove the index from the stack
            }
            if (i < n) {
                s.push(i);  // Only push indices from the first pass
            }
        }
        
        return ans;
    }
};
