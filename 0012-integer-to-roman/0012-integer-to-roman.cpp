class Solution {
public:
    string intToRoman(int num) {
        // Arrays to store the values and corresponding Roman symbols
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        int i = 0; // Pointer to navigate through the arrays
        string str = ""; // String to store the final Roman numeral
        
        // Iterate while the number is greater than 0
        while (num > 0) {
            // If current numeral can be subtracted from num, append it to result
            if (num >= n[i]) {
                str += s[i]; // Append the corresponding Roman numeral
                num -= n[i]; // Decrease the number by the numeral's value
            } else {
                i++; // Move to the next smaller numeral
            }
        }
        
        return str; // Return the final Roman numeral
    }
};
