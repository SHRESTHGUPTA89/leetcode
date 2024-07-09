class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        vector<int>ans;
        
        while(i<n){
            
            int correct= nums[i] -1 ; // tell us correct index for nums in sorting terms
            
            if(   nums[i] != nums[correct]){
                
                swap(nums[i] , nums[correct] );
                
            }
            else{
                i++;
            }   
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i]!=i+1){
                ans.push_back(i+1);
            }
        }
        
        
        return ans;
        
    }
};