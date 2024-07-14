class Solution {
public:
    string getSmallestString(string s) {
        string ans = s;
        for(int i=0;i<s.size()-1;i++) // O(n)
        {
            if((s[i]-'0')%2==(s[i+1]-'0')%2)
            {
                string copy = s;
                swap(copy[i],copy[i+1]);
                ans=min(copy,ans); // O(n)
            }
        }
        return ans;
    }
    // tc - O(n^2)
    // sc - O(n)
};