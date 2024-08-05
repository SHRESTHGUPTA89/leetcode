#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> freqMap;
        
        // Count the frequency of each string in the array
        for (const auto& str : arr) {
            freqMap[str]++;
        }
        
        // Traverse the array again to find the k-th distinct string
        int count = 0;
        for (const auto& str : arr) {
            if (freqMap[str] == 1) {
                count++;
                if (count == k) {
                    return str;
                }
            }
        }
        
        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
};
