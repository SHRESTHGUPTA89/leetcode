class Solution {
public:
    int minChanges(string s) {
        int ans = 0, i = 0;

        while (i < s.length()) {
            ans += (s[i++] ^ s[i++]) ? 1 : 0; // Adds 1 if characters are different
        }

        return ans;
    }
};
