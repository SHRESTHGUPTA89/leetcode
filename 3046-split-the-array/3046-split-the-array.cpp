class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]>2)return false;
        }
        
    return true;
    }
    };