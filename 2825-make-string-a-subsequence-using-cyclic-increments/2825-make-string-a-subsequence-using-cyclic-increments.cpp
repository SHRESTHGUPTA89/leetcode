class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0; // Pointer for str2
        
        for (char k : str1) {
            // Check if the current character in str1 matches the current character in str2
            // Either directly, by incrementing (wrapping z to a), or cycling
            if (j < str2.size() && (k == str2[j] || (k == 'z' && str2[j] == 'a') || (k + 1 == str2[j]))) {
                j++; // Move to the next character in str2
            }
        }
        
        // If we've matched all characters in str2, return true
        return j == str2.size();
    }
};
