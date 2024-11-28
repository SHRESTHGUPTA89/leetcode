class Solution {
public:
    vector<vector<int>> dp; // DP table for memoization

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    int solve(string &s, int i, int j) {
        // Base case: If the substring length is 1 or 0, no cuts are needed
        if (i >= j || isPalindrome(s, i, j)) {
            return 0;
        }

        // If already computed, return the stored result
        if (dp[i][j] != -1) return dp[i][j];

        int mn = INT_MAX;

        // Partition the string and solve recursively
        for (int k = i; k < j; k++) {
            if (isPalindrome(s, i, k)) { // Only partition if the left part is a palindrome
                int temp = 1 + solve(s, k + 1, j); // Add 1 cut and solve for the right part
                mn = min(mn, temp); // Take the minimum cuts
            }
        }

        return dp[i][j] = mn; // Store the result in the DP table
    }

    int minCut(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1)); // Initialize DP table with -1
        return solve(s, 0, n - 1); // Solve for the entire string
    }
};
