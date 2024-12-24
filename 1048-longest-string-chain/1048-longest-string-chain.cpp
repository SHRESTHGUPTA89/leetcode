#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compare two strings and check if s1 can be derived from s2 by adding one character
    bool compare(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1) return false; // Ensure s1 is exactly one character longer than s2
        
        int first = 0, second = 0;

        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        // Ensure all characters in s2 were matched in s1
        return second == s2.size();
    }

    // Comparator to sort strings by length
    static bool comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();

            sort(arr.begin(), arr.end(), comp);
    

        vector<int> dp(n, 1); // DP array to store the longest chain ending at each string
        int maxi = 1; // To store the maximum length of the string chain

        // Iterate over each string to build the DP table
        for (int i = 0; i < n; i++) {
            for (int prev_index = 0; prev_index < i; prev_index++) {
                // If arr[i] can follow arr[prev_index] in the chain
                if (compare(arr[i], arr[prev_index]) && dp[prev_index] + 1 > dp[i]) {
                    dp[i] = dp[prev_index] + 1;
                }
            }
            // Update the maximum chain length
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};



    