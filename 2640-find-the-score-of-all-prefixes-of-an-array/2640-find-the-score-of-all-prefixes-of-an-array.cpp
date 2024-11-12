class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>conv;
        int maxi=0;
        for(int i=0;i<n;i++){
            
            maxi=max(maxi,nums[i]);
            
            int k=nums[i]+maxi;
            conv.push_back(k);
        }
        
        vector<long long>score;
        long long h=0;
        
        for(int i=0;i<n;i++){
            
             h+=conv[i];
            score.push_back(h);
        }
        
        return score;
    }
};