class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();


        if (len1 > len2) return false;

        // Frequency arrays for s1 and for the sliding window in s2
        vector<int> freqS1(26, 0), freqWindow(26, 0);

        // Count frequencies of characters in s1
        for (int i = 0; i < len1; i++) {
            freqS1[s1[i] - 'a']++;
            freqWindow[s2[i] - 'a']++;
        }

        // Check if the initial window matches
        if (freqS1 == freqWindow) return true;

        // Start sliding the window
        for (int i = len1; i < len2; i++) {
            // Add new character to the window
            freqWindow[s2[i] - 'a']++;
            // Remove the character that's sliding out of the window
            freqWindow[s2[i - len1] - 'a']--;

            // Check if the current window matches
            if (freqS1 == freqWindow) return true;
        }

        return false;
    }
};
