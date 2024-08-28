#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mpp; // Corrected from 'unsorted_map' to 'unordered_map'
        vector<int> ans;
        
        // Count the frequency of each element
        for (auto a : nums) {
            mpp[a]++;
        }
        
        // Create a max-heap (priority queue) where the first element of the pair is the negative frequency 
        // (to sort by increasing frequency), and the second is the element itself.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto a : mpp) {
            pq.push({-a.second, a.first}); // Push negative frequency to sort by frequency first, and then by value.
        }
        
        // Extract elements from the heap
        while (!pq.empty()) {
            int freq = -pq.top().first; // Convert the negative frequency back to positive
            int value = pq.top().second;
            for (int i = 0; i < freq; i++) {
                ans.push_back(value);
            }
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

