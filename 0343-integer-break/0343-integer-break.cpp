class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        for (int i = 2; i < n; i++) {
            int div = n / i;
            int mod = n - i * div;
            int v = std::pow(div+1, mod) * std::pow(div, i-mod);
            if (v < res) return res;
            res = v;
        }
        return res;
    }
};