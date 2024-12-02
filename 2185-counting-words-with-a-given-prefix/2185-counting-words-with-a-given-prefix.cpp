class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(string word:words){
            
            if(word.substr(0,pref.length())==pref){
                c++;
            }
            
            
        }
        return c;
    }
};