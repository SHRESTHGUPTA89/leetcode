class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(candidates, target, 0, result, temp);
        return result;
    }

    void solve(vector<int>& candidates, int target, int start, vector<vector<int>>& result, vector<int> temp) {
        int sum = accumulate(temp.begin(), temp.end(), 0);
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if( i > start && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates, target, i+1, result, temp);  
            temp.pop_back();
        }
    }
};

    