class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        sort(s1.begin(), s1.end());

        int len1 = s1.size();
        int len2 = s2.size();

        
        for (int i = 0; i <= len2 - len1; i++) {
            
            string r = s2.substr(i, len1);
            
            
            sort(r.begin(), r.end());


            if (r == s1) {
                return true;
            }
        }

        return false;
    }
};
