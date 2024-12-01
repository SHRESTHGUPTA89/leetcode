class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int target = 2 * arr[i];
            int s = 0, e = n - 1;

            while (s <= e) {
                int m = s + (e - s) / 2;

                // Ensure we are not comparing the element to itself
                if (m != i && arr[m] == target) {
                    return true;
                }

                if (arr[m] < target) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }

        return false;
    }
};
