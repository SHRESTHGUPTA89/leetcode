class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;

        for (char digit : num) {
            // Remove elements from the stack if the current digit is smaller than the stack's top element
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // If k is still greater than 0, remove the remaining elements from the end
        while (k > 0) {
            stack.pop_back();
            k--;
        }

        // Build the resulting number string
        string result = "";
        bool leadingZero = true;
        for (char digit : stack) {
            if (leadingZero && digit == '0') {
                continue; // Skip leading zeros
            }
            leadingZero = false;
            result += digit;
        }

        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};
