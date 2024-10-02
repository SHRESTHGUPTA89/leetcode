class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};  // Handle empty array
        
        // Create a vector of pairs to store the original values and their indices
        vector<pair<int, int>> k;
        
        // Fill the vector with pairs (value, original index)
        for (int i = 0; i < n; i++) {
            k.push_back({arr[i], i});
        }
        
        // Sort the vector based on the values (first element of the pair)
        sort(k.begin(), k.end());
        
        // Create a vector to store the ranks of the elements
        vector<int> rank(n);
        
        int currentRank = 1;
        rank[k[0].second] = currentRank; // The smallest element gets rank 1
        
        // Iterate over the sorted vector to assign ranks
        for (int i = 1; i < n; i++) {
            // If the current value is different from the previous, increment the rank
            if (k[i].first != k[i-1].first) {
                currentRank++;
            }
            rank[k[i].second] = currentRank;
        }
        
        // Return the ranked array
        return rank;
    }
};

