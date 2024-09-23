class Solution {
public:
    int integerBreak(int n) {
        // Base cases
        if (n == 2) return 1;
        if (n == 3) return 2;

        // General case: break n into as many 3's as possible
        int product = 1;

        while (n > 4) {
            product *= 3;
            n -= 3;
        }

        // Multiply the remaining n, which will be 2, 3, or 4
        product *= n;

        return product;
    }
};
