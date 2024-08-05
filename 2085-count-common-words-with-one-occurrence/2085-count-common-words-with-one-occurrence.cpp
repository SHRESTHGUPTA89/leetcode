#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        std::unordered_map<std::string, int> freq1;
        std::unordered_map<std::string, int> freq2;
        
        // Count the frequency of each word in words1
        for (const auto& word : words1) {
            freq1[word]++;
        }
        
        // Count the frequency of each word in words2
        for (const auto& word : words2) {
            freq2[word]++;
        }
        
        int count = 0;
        
        // Iterate through freq1 to find common words with exactly one occurrence
        for (const auto& entry : freq1) {
            const std::string& word = entry.first;
            if (entry.second == 1 && freq2[word] == 1) {
                count++;
            }
        }
        
        return count;
    }
};
