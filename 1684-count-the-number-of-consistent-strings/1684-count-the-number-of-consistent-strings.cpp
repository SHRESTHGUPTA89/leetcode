class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set or array for allowed characters
        vector<bool> allowedSet(26, false);
        for (char c : allowed) {
            allowedSet[c - 'a'] = true;
        }
        
        int consistentCount = 0;
        
        // Check each word in the words vector
        for (const string& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (!allowedSet[c - 'a']) {
                    isConsistent = false;
                    break;
                }
            }
            
            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }
        
        return consistentCount;
    }
};
