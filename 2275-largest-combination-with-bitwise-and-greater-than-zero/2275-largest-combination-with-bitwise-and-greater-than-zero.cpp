
class Solution {
public:
    int solve(int i,int bit,vector<int> &candidates,vector<vector<int>> &dp){
        if(i == candidates.size()) return 0;
        if(dp[i][bit] != -1) return dp[i][bit];

        int take = 0;
        int setbit = 1<<bit & candidates[i];
        if(setbit) take = 1 + solve(i+1,bit,candidates,dp);
        int skip = solve(i+1,bit,candidates,dp);
        return dp[i][bit] = max(take,skip);
    }
    int largestCombination(vector<int>& candidates) {
        int ans = 1;
        int n = candidates.size();
        vector<vector<int>> dp(n+1,vector<int>(24,-1));
        for(int i = 0;i<24;i++){
            ans = max(ans,solve(0,i,candidates,dp));
        }
        return ans;
    }
};