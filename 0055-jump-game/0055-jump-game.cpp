class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int start=0;
        int end=n-1;
        
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=end-i){
                end=i;
            }
        }
        
        return end==0;
    }
};