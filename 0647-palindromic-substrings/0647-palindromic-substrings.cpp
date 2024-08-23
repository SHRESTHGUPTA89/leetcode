class Solution {
public:
    
int expandAroundCenter(const string &s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}
    int countSubstrings(string input) {

    int n = input.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        // Odd-length palindromes
        count += expandAroundCenter(input, i, i);
        // Even-length palindromes
        count += expandAroundCenter(input, i, i + 1);
    }

    return count;
}
    
};