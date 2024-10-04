class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n=skill.size();
        
        if(n==2){
            return skill[0]*skill[1];
        }
        
        vector<pair<int,int>>v;
        
        sort(skill.begin(),skill.end());
        
        int i=0,j=n-1;
    int    target= skill[0] + skill[n-1];
        int k=0;
        while(i<j){
            
            k=skill[i] + skill[j] ;
            
            
            
            if(k == target){
                
                v.push_back({skill[i],skill[j]});
                i++;
                j--;
            }
            
            else if(k>target){
                j--;
            }
            
            else{
                i++;
            }
           
            
        }
        
        if(v.size() != n/2){
            return -1;
        }
        long long sum=0;
        
        for(auto t:v){
            
            sum= sum + t.first * t.second;
            
        }
        
        return sum;
        
    }
};