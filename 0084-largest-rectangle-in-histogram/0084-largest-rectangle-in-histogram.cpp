class Solution {
public:
    vector<int> NSR(vector<int>& heights, int n) {
        stack<pair<int, int>> st;
        vector<int> nsr(n, n);  // Initialize NSR with 'n' as the default value

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nsr[i] = st.top().second;
            }

            st.push({heights[i], i});
        }

        return nsr;
    }

    vector<int> NSL(vector<int>& heights, int n) {
        stack<pair<int, int>> st;
        vector<int> nsl(n, -1);  // Initialize NSL with '-1' as the default value

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nsl[i] = st.top().second;
            }

            st.push({heights[i], i});
        }

        return nsl;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Get the NSR and NSL for all elements
        vector<int> nsr = NSR(heights, n);
        vector<int> nsl = NSL(heights, n);

        int max_area = 0;

        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = width * heights[i];
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
