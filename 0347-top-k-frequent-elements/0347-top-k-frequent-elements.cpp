#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        typedef pair<int, int> ppi;   
        // Min-heap to store the frequency and the corresponding number
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<int> ans;
        
        unordered_map<int, int> mpp;
        
        // Count the frequency of each element
        for(int a : nums) {
            mpp[a]++;
        }
        
        // Build the heap based on frequency
        for (auto a : mpp) {
            pq.push({a.second, a.first});
            
            // Maintain the heap size to be at most k
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Extract elements from the heap
        while (!pq.empty()) {
            ans.push_back(pq.top().second);  // Push the element (number), not the frequency
            pq.pop();
        }
        
        return ans;
    }
};
