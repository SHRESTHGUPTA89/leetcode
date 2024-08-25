class Solution {
public:
    vector<int> NSL(vector<int>& nums, int n) {
        stack<pair<int, int>> st;
        vector<int> nsl(n, -1);  // Initialize NSL with '-1' as the default value

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nsl[i] = st.top().second;
            }

            st.push({nums[i], i});
        }

        return nsl;
    }
    
    vector<int> NSR(vector<int>& nums, int n) {
        stack<pair<int, int>> st;
        vector<int> nsr(n, n);  // Initialize NSR with 'n' as the default value

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first > nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nsr[i] = st.top().second;
            }

            st.push({nums[i], i});
        }

        return nsr;
    }

    vector<int> PGL(vector<int>& nums, int n) {
        stack<pair<int, int>> st;
        vector<int> pgl(n, -1);  // Initialize PGL with '-1' as the default value

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pgl[i] = st.top().second;
            }

            st.push({nums[i], i});
        }

        return pgl;
    }

    vector<int> NGR(vector<int>& nums, int n) {
        stack<pair<int, int>> st;
        vector<int> ngr(n, n);  // Initialize NGR with 'n' as the default value

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first < nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ngr[i] = st.top().second;
            }

            st.push({nums[i], i});
        }

        return ngr;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        // Get indices of the Next Smaller Element (NSR) and Previous Smaller Element (NSL)
        vector<int> nsr = NSR(nums, n);
        vector<int> nsl = NSL(nums, n);

        // Get indices of the Next Greater Element (NGR) and Previous Greater Element (PGL)
        vector<int> ngr = NGR(nums, n);
        vector<int> pgl = PGL(nums, n);

        long long sumMin = 0, sumMax = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - nsl[i];
            long long rightMin = nsr[i] - i;
            sumMin += leftMin * rightMin * nums[i];

            long long leftMax = i - pgl[i];
            long long rightMax = ngr[i] - i;
            sumMax += leftMax * rightMax * nums[i];
        }

        return sumMax - sumMin;
    }
};
