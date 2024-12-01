class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        
        int jump=0,coverage=0,lastjump=0;
        
        for(int i=0;i<n;i++){
            
            coverage=max(coverage,i+nums[i]);
            
            if(i==lastjump){
                lastjump=coverage;
                jump++;
                
                if(coverage >= n-1){
                    return jump;
                }
            }
            
            
            
            
        }
        
        return 0;
        
        
    }
};