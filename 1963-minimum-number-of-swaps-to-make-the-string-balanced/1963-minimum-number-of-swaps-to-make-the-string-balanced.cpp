class Solution {
public:
    int minSwaps(string s) {
        int size = 0; // keeps track of unbalanced '[' brackets
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '[') 
                size++; // count unbalanced '[' brackets
            else if (size > 0) 
                size--; // balance with a ']' bracket
        }
        return (size + 1) / 2; // return minimum swaps needed
    }
};
