class Solution {
public:
    int binary(vector<vector<int>>& items,int q){
        int k=0;
        int s=0;
        int e= items.size()-1;
        while(s<=e){
            
            
            int m=s+(e-s)/2;
            if(items[m][0]>q){
                e=m-1;
            }
            else if(items[m][0]<=q){
                k=items[m][1];
                s=m+1;
                
            }
            
            
        }
        
        
        return k;
    }
    
    
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m=queries.size();
        
        sort(items.begin(),items.end());
        int maxi=0;
        for(int i=0;i<n;i++){
            
             maxi=max(maxi,items[i][1]);
             items[i][1]=maxi;
            
        }
        vector<int>ans;
        
        for(int i=0;i<m;i++){
            
            
            int k=binary(items,queries[i]);
            
            ans.push_back(k);
            
            
        }
        return ans;
        
    }
};