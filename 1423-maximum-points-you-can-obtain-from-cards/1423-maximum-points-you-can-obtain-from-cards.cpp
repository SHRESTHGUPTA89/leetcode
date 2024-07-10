class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        
        
        
        int n=cardPoints.size();
        
        if(k>n){
            return 0;
        }
        int lsum=0;
        int rsum=0;
        int maxsum=0;
        
        for(int i=0;i<=k-1;i++){
            lsum+=cardPoints[i];
        }
        maxsum=lsum;
       int  Rindex=n-1;
        
        for(int i=k-1;i>=0;i--){
            // doing these step to maintain the k=4 elements
            lsum-=cardPoints[i];
            rsum+=cardPoints[Rindex];
            Rindex--;
            maxsum=max(maxsum,rsum+lsum);
            
        }
        
        
        return maxsum;
        
        
     
        
        //T.C=o(2k) ----> o(1) constant best solution
        
    }
};