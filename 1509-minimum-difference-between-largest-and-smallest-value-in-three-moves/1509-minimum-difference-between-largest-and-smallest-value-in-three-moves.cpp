class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());

        int opt1=nums[n-4] - nums[0];
        int opt2=nums[n-3] - nums[1];
        int opt3=nums[n-2] - nums[2];
        int opt4=nums[n-1] - nums[3];

        //return min(opt1,min(opt2,min(opt3,opt4)));
        return min({opt1,opt2,opt3,opt4});
    
        
    }
};