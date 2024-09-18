#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Comparison function to sort numbers in the desired order
    static bool comp(const int &a, const int &b) {
        string strA = to_string(a); // or we can write if(s1+s2 > s2+s1){ return true;} return false;}
        string strB = to_string(b);
        return strA + strB > strB + strA;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        
        // Handle the edge case where the largest number is 0
        if (nums[0] == 0) return "0";

        string result;
        for (int num : nums) {
            result += to_string(num);
        }
        
        return result;
    }
};
