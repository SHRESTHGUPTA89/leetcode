class Solution {
public:
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
    
    vector<int> NSR(vector<int>& heights, int n) {
        stack<pair<int, int>> st;
        vector<int> nsr(n, n);  // Initialize NSR with 'n' as the default value

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first > heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nsr[i] = st.top().second;
            }

            st.push({heights[i], i});
        }

        return nsr;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> right = NSR(arr, n);
        vector<int> left = NSL(arr, n);
        long long sum = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int l = i - left[i];
            int r = right[i] - i;
            long long k = (long long)l * r * arr[i];  // Convert to long long to avoid overflow
            sum = (sum + k) % mod;
        }

        return sum;
    }
};
