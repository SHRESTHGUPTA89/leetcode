#include <string>
#include <sstream>

class Solution {
public:
    int getLucky(std::string s, int k) {
        std::string transformed;

        // Step 1: Convert each character to its position in the alphabet
        for (char ch : s) {
            int val = ch - 'a' + 1;  // Convert 'a' -> 1, 'b' -> 2, etc.
            transformed += std::to_string(val);  // Append the string representation of the number
        }

        // Step 2: Perform the sum of digits operation k times
        int sum = 0;
        while (k--) {
            sum = 0;
            for (char ch : transformed) {
                sum += ch - '0';  // Convert character digit to integer and add to sum
            }
            transformed = std::to_string(sum);  // Update transformed string with the sum as a string
        }

        return sum;  // Return the final sum after k iterations
    }
};
