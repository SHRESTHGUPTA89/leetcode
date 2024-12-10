class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        int maxLength = -1; // Initialize as -1 for no valid substring

        // Iterate through all possible substring lengths
        for (int len = 1; len <= n; len++) {
            unordered_map<string, int> freqMap;

            // Extract all substrings of the current length
            for (int i = 0; i <= n - len; i++) {
                string sub = s.substr(i, len);

                // Check if the substring is "special" (all characters are the same)
                if (isSpecial(sub)) {
                    freqMap[sub]++;
                }
            }

            // Check the frequency of substrings
            for (auto& [sub, freq] : freqMap) {
                if (freq >= 3) {
                    maxLength = max(maxLength, len);
                }
            }
        }

        return maxLength;
    }

private:
    bool isSpecial(const string& sub) {
        char firstChar = sub[0];
        for (char c : sub) {
            if (c != firstChar) return false;
        }
        return true;
    }
};
