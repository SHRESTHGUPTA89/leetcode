#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mapp;

        // Populate the map with frequency counts
        for(int i = 0; i < n; i++) {
            mapp[nums[i]]++;
        }

        // Create a vector of pairs to store the map elements for sorting
        vector<pair<int, int>> value(mapp.begin(), mapp.end());

        // Sort the vector by frequency and by value if frequencies are the same
        sort(value.begin(), value.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second != b.second)
                return a.second < b.second;
            return a.first > b.first;
        });

        // Create the result vector
        vector<int> ans;
        for(auto& ch : value) {
            for(int i = 0; i < ch.second; i++) {
                ans.push_back(ch.first);
            }
        }

        return ans;
    }
};
