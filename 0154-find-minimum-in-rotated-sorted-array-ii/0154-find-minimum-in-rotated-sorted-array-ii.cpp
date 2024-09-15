class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while (s < e) {
            int m = s + (e - s) / 2;

            // If arr[m] is greater than arr[e], the minimum is in the right half
            if (arr[m] > arr[e]) {
                s = m + 1;
            }
            // If arr[m] is less than arr[e], the minimum is in the left half (including mid)
            else if (arr[m] < arr[e]) {
                e = m;
            }
            // When arr[m] == arr[e], we can't determine which half to go,
            // so we reduce the search space from the right by decrementing e.
            else {
                e--;
            }
        }

        // After the loop, s == e, which is the index of the minimum element
        return arr[s];
    }
};
