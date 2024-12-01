class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>s;
        
        for(int a:arr){
            if(s.find(a*2)!=s.end() || (s.find(a/2)!=s.end() && a%2==0) ){
                return true;
            }
            s.insert(a);
        }
        
        return false;
    }
};