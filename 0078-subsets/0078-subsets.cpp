class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        int n=nums.size();
        int N=1<<n;
        vector<vector<int>>ans;
        
        for(int i=0;i<N;i++){
            vector<int>sub;
            
            for(int j=0;j<n;j++){
                if((i & (1<<j)) != 0){
                    sub.push_back(nums[j]);
                }
            }
            
            
            ans.push_back(sub);
        }
        
        return ans;
    }
};