class Solution {
public:
    // Renamed the function to avoid conflict with built-in XOR operator
    int computeXor(int a, int b, vector<int>& arr) {
        int xorr = 0;
        for (int i = a; i <= b; i++) {
            xorr = xorr ^ arr[i];
        }
        return xorr;
    }

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size(); // Number of queries
        vector<int> ans(n); // Vector to store results, already sized `n`

        for (int i = 0; i < n; i++) {
            // Use the renamed `computeXor` function
            int k = computeXor(queries[i][0], queries[i][1], arr);
            ans[i] = k; // Assign result directly
        }

        return ans; // Return the results vector
    }
};
