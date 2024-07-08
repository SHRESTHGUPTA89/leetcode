class Solution {
public:
    
    
    int findTheWinnerIdx(int n,int k){
        
        if(n==1){
            return 0;
        }
        
        int Idx=findTheWinnerIdx(n-1,k);
        
        Idx=(Idx+k)%n; // to find the original index int original array
        
        return Idx;
    }
    
    int findTheWinner(int n, int k) {
        
        
        int result_idx=findTheWinnerIdx(n,k);
        
        return result_idx +1;
        
        // T.C=O(n)
        
    }
};