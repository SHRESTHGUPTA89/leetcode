#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mappp;
        int left = 0, right = 0, maxi = 0;
        
        while (right < s.length()) {
            mappp[s[right]]++;
            
            while (mappp[s[right]] > 1) {
                mappp[s[left]]--;
                left++;
            }
            
            maxi = max(maxi, right - left + 1);
            right++;
        }
        
        return maxi;
    }
};
