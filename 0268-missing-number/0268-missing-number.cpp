class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        
        while(i<n){
            
            int correct= nums[i]; // tell us correct index for nums in sorting terms
            
            if(correct < n       &&   nums[i] != nums[correct]){
                
                swap(nums[i] , nums[correct] );
                
            }
            else{
                i++;
            }   
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i]!=i){
                return i;
            }
        }
        
        
        return n;
        
        // full solution based on cycle sort
    }
};