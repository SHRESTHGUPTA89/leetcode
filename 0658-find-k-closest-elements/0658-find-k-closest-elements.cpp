
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for (int a : arr) {
            int diff = abs(x - a);
            pq.push({diff, a});
            
            // Maintain the heap size to be at most k
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Extract elements from the heap
        while (!pq.empty()) {
            ans.push_back(pq.top().second);  // Only push the element, not the difference
            pq.pop();
        }
        
        // Sort the result since the heap doesn't guarantee order
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
