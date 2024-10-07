class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            // If the current character forms "AB" with the top of the stack, pop the top
            if (!st.empty() && st.top() == 'A' && c == 'B') {
                st.pop();
            }
            // If the current character forms "CD" with the top of the stack, pop the top
            else if (!st.empty() && st.top() == 'C' && c == 'D') {
                st.pop();
            }
            // Otherwise, push the current character onto the stack
            else {
                st.push(c);
            }
        }

        // The length of the stack is the length of the remaining string
        return st.size();
    }
};
