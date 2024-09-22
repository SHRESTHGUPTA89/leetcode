class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

    
        for(char a: columnTitle) {
            
            ans = ans * 26 + (a - 'A' + 1);
        }

        return ans;
    }
};
