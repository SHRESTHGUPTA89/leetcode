class Solution {
public:
    bool canJump(vector<int>& nums) {
        
   //      greedy method
        
        // hum loog end ko laga taar last se first move kar rahe for detail watch nikhal lohia
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