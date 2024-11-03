class Solution {
public:
    bool rotateString(string s, string goal) {
        int ans=0,j=0;
        int n=s.length();
        if(n> goal.size()) return false;
        for(int i=0;i<n;i++){
            s.push_back(s[i]);
            if(s.substr(i+1)==goal) return true;
            cout<<s.substr(i+1)<<endl;
        }
        return s.substr(ans)==goal;
    }
};