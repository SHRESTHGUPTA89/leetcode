class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v = arr; // Copy the array
        sort(v.begin(), v.end());

        int balance = 0; // Tracks the net balance
        unordered_map<int, int> freq; // Tracks frequency differences
        int ans = 0;

        for (int i = 0; i < v.size(); ++i) {
            freq[v[i]]++;
            if (freq[v[i]] == 0) freq.erase(v[i]); // Remove if balanced

            freq[arr[i]]--;
            if (freq[arr[i]] == 0) freq.erase(arr[i]); // Remove if balanced

            // If the frequency map is empty, we found a chunk
            if (freq.empty()) ans++;
        }

        return ans;
    }
};

