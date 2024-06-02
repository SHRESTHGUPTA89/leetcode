class Solution {
public:
    void reverseString(vector<char>& s, int i = 0) {
        int n = s.size();

        // Base case: if we have reached the middle, stop recursion
        if (i >= n / 2) {
            return;
        }

        // Swap the current element with the corresponding element from the end
        swap(s[i], s[n - i - 1]);

        // Recursive call to reverse the next elements
        reverseString(s, i + 1);
    }
};
