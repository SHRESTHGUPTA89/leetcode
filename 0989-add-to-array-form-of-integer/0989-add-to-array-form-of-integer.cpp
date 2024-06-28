class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int j = num.size();
        int carry=0;
        vector<int> ans;
        while(j > 0 || carry > 0 || k > 0){

            if(j>0){
                carry=carry + num[j-1];
                j--;
            }

            carry = carry + k%10;
            k = k/ 10;
            ans.push_back(carry%10);

            carry= carry / 10;

        }

        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};