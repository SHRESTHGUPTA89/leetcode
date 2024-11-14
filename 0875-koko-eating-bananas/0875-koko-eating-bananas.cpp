class Solution {
public:
    
    bool solve(vector<int>& piles , int k, int h){
        
        double hours=0;
        for(int &a : piles){
            
            hours += ceil((double)a / k);
            
            
            
        }
        
        
        
        return hours<=h;
        
        
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
    int s=0;
    int e=*max_element(piles.begin(), piles.end());
    int ans=0;   
        
    while(s<=e){
        
        int m=s+(e-s)/2;
        if(solve(piles, m, h)){
            ans=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
        
        
    }    
        
        return ans;
    }
};