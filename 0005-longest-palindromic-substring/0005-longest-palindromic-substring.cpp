class Solution {
public:
    
    // Helper function to expand around the center and find the length of the palindrome
int expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}
    string longestPalindrome(string str) {

    if (str.empty()) return ""; // Handle empty string case
    int start = 0, end = 0;

    for (int i = 0; i < str.length(); i++) {
        // Consider odd-length palindromes (centered at a single character)
        int len1 = expandAroundCenter(str, i, i);
        // Consider even-length palindromes (centered between two characters)
        int len2 = expandAroundCenter(str, i, i + 1);
        // Find the maximum length palindrome
        int len = max(len1, len2);
        
        // Update start and end positions if a longer palindrome is found
        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    // Extract the longest palindromic substring
    return str.substr(start, end - start + 1);
}
    
};