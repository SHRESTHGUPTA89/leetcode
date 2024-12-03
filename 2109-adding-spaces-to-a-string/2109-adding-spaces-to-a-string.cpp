class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        int m = spaces.size();
        int j = 0; // Index for spaces vector
        
        for (int i = 0; i < n; i++) {
            // If current index matches the next space index, add a space
            if (j < m && i == spaces[j]) {
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        
        return ans;
    }
};
