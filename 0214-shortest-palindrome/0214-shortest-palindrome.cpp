class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Create a new string that concatenates s, a special character, and the reversed s
        string l = s + "#" + rev_s;
        
        // Compute the KMP table (prefix function)
        vector<int> table(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = table[i - 1];
            while (j > 0 && l[i] != l[j]) {
                j = table[j - 1];
            }
            if (l[i] == l[j]) {
                j++;
            }
            table[i] = j;
        }
        
        // The length of the palindrome prefix is given by the last value in the table
        int palindrome_len = table.back();
        
        // Append the non-palindrome part (i.e., the suffix) in reverse to the start of the string
        return rev_s.substr(0, s.size() - palindrome_len) + s;
    }
};
