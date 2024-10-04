class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum=0;
        int n= nums.size();
        unordered_map<int,int>m;
        m[0]=1;
        int count=0;
        
        for(int i=0;i<n;i++){
            
             sum=sum+nums[i];
             
             int remainder= sum % k;
             if(remainder < 0){
                 remainder+=k;
             }
            
             if(m.find(remainder)!=m.end()){
                 count+=m[remainder];
             }
            
            
            m[remainder]++;
            
        }
        
        return count;
        
    }
};

