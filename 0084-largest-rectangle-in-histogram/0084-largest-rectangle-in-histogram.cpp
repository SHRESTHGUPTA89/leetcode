#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // While the current height is less than the height of the bar at the stack's top
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        // After iterating through the array, process any remaining bars in the stack
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};