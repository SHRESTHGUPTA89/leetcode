class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); ++i) {
            int rem = target - nums[i];
            if(mapp.find(rem) != mapp.end()) {
                ans.push_back(mapp[rem] + 1);
                ans.push_back(i + 1);
                break;
            }
            mapp[nums[i]] = i;
        }
        
        return ans;
    }
};
