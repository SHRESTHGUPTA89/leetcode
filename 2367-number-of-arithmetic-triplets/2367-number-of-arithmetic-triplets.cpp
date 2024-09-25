class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> seen;
        int count = 0;

        // Iterate through the array
        for (int num : nums) {
            // Check if there exist two previous numbers that form an arithmetic triplet
            if (seen.count(num - diff) && seen.count(num - 2 * diff)) {
                count++;
            }
            // Add the current number to the set
            seen.insert(num);
        }

        return count;  // Return the total count of arithmetic triplets
    }
};


