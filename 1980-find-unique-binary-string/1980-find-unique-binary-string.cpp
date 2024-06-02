class Solution {
public:
    int N;
    vector<string> result;

    void solve(string str, int start) {
        if (str.size() == N) {
            result.push_back(str);
            return;
        }

        str.push_back('0');
        solve(str, start + 1);
        str.pop_back();

        str.push_back('1');
        solve(str, start + 1);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        N = nums.size();
        string str = "";
        solve(str, 0);

        for (const auto& v : result) {
            if (find(nums.begin(), nums.end(), v) == nums.end()) {
                return v;
            }
        }
        
        return "";
    }
};
