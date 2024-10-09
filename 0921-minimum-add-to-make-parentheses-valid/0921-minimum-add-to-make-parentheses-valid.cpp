class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftUnmatched = 0;  // Tracks unmatched '('
        int rightUnmatched = 0; // Tracks unmatched ')'

        for (char ch : s) {
            if (ch == '(') {
                leftUnmatched++;  // Opening parenthesis increases unmatched '(' count
            } else if (leftUnmatched > 0) {
                leftUnmatched--;  // Match with an unmatched '('
            } else {
                rightUnmatched++; // Unmatched ')'
            }
        }
        
        
        return leftUnmatched + rightUnmatched;
    }
};
