class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        // No need to handle the case where size == 1 separately, it can't repeat
        if (n == 1) return false;
        
        // Try all possible lengths of substrings from 1 to n/2
        for (int len = 1; len <= n / 2; ++len) {
            if (n % len == 0) { // Ensure the current length divides the string's total length
                string r = s.substr(0, len); // Get the candidate substring
                
                // Compare this substring with the rest of the string
                bool valid = true;
                for (int i = len; i < n; i += len) {
                    if (s.substr(i, len) != r) {
                        valid = false;
                        break;
                    }
                }
                
                // If valid, we found a repeating pattern
                if (valid) return true;
            }
        }
        
        return false; // No valid repeating pattern found
    }
};
