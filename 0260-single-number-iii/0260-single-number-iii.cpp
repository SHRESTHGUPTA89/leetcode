class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long long xor_r=0;

        for(int &num : nums){
            xor_r ^=num;
        }
        int mask=(xor_r) & (-xor_r);

        int groupA=0;
        int groupB=0;
        for(int &num: nums){
            if(num & mask){
                groupA ^= num;
            }

            else{
                groupB ^= num;
            }
        }

        return{groupA,groupB};
    }
};