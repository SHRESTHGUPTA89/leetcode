class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0; // Bitmask to track even/odd counts of vowels
        int longest = 0;
        
        // HashMap to store the first occurrence of each bitmask
        unordered_map<int, int> maskMap;
        maskMap[0] = -1; // Initial condition to handle the case when the substring starts from index 0
        
        for (int i = 0; i < n; ++i) {
            // Update the bitmask when a vowel is found
            if (s[i] == 'a') {
                mask ^= (1 << 0); // Toggle bit 0 for 'a'
            } else if (s[i] == 'e') {
                mask ^= (1 << 1); // Toggle bit 1 for 'e'
            } else if (s[i] == 'i') {
                mask ^= (1 << 2); // Toggle bit 2 for 'i'
            } else if (s[i] == 'o') {
                mask ^= (1 << 3); // Toggle bit 3 for 'o'
            } else if (s[i] == 'u') {
                mask ^= (1 << 4); // Toggle bit 4 for 'u'
            }

            // If this bitmask has been seen before, calculate the substring length
            if (maskMap.find(mask) != maskMap.end()) {
                longest = max(longest, i - maskMap[mask]);
            } else {
                // Otherwise, store the first occurrence of this bitmask
                maskMap[mask] = i;
            }
        }

        return longest;
    }
};
