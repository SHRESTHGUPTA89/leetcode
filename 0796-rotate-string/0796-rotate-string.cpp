//Approach-2 (Concatenation with itself contains all possible rotations)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();
        
        if(m == n && (s+s).find(goal) != string::npos)
            return true;
        
        return false;
    }
};
