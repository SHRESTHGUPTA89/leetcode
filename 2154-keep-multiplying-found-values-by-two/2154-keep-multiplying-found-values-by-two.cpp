class Solution {
public:
    int findFinalValue(vector<int>& arr, int original) {
        sort(arr.begin(), arr.end()); 

        int n = arr.size();

        while (true) {
            int s = 0, e = n - 1;
            bool found = false;

            while (s <= e) {
                int m = s + (e - s) / 2;

                if (arr[m] == original) {
                    original *= 2; // Double the value
                    found = true;  // Mark as found
                    break;
                }

                if (arr[m] < original) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }

            // If no match was found, exit the loop
            if (!found) break;
        }

        return original;
    }
};
