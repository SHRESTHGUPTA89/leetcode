class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        map<int,int> mapp;
        int i=0;
        for(auto &num: nums){
            
            int rem=target- num;
            
            if(mapp.find(rem)!=mapp.end()){
                return{i,mapp[rem]};
            }
            
            
            
            
            
            mapp[num]=i;
            i++;
        }
        
        return {-1,-1};
        
    }
};