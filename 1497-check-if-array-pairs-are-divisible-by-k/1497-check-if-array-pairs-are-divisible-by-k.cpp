class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        int n = arr.size();

        // Calculate remainder of each element and count their frequencies
        for (int i = 0; i < n; i++) {
            int rem = ((arr[i] % k) + k) % k; // Handling negative numbers correctly
            remainderCount[rem]++;
        }

        // Check for valid pairings
        if (remainderCount[0] % 2 != 0) {
            return false; // Elements divisible by k should be in pairs
        }

        for (int i = 1; i < k; i++) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false; // The count of remainders i and k-i should match
            }
        }

        return true;
    }
};
