#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:

    bool happens(const std::vector<int>& quantities, int n, int mid) {
        int count = 0;

        for (int i = 0; i < quantities.size(); i++) {
            // Correct way to calculate ceil division for integers
            count += (quantities[i] + mid - 1) / mid;
        }

        return count <= n;
    }

    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int s = 1;
        int e = *std::max_element(quantities.begin(), quantities.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (happens(quantities, n, mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};
