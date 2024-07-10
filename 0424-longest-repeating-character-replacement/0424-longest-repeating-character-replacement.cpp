#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int n = s.length();
        unordered_map<char, int> count;
        int max_count = 0;
        int maxi = 0;

        while (r < n) {
            count[s[r]]++;
            max_count = max(max_count, count[s[r]]);

            while ((r - l + 1) - max_count > k) {
                count[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};
