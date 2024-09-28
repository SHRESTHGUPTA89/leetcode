class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0, j = 0;

        // Traverse both lists with two pointers
        while (i < firstList.size() && j < secondList.size()) {
            // Find the start and end of the intersection
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // If they intersect, add the intersection to the result
            if (start <= end) {
                result.push_back({start, end});
            }

            // Move the pointer of the interval that ends earlier
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};
