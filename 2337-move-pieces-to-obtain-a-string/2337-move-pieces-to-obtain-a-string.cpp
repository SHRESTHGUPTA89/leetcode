class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int m = target.size();

    
        if (m != n) {
            return false;
        }

        string s = "", t = "";
        for (int i = 0; i < n; i++) {
            if (start[i] != '_') s += start[i];
            if (target[i] != '_') t += target[i];
        }

        if (s != t) {
            return false;
        }
        
              // Check positional constraints for 'L' and 'R'.
        int j = 0, k = 0;
        while (j < n && k < n) {
            // Find the next non-underscore character in both strings.
            while (j < n && start[j] == '_') j++;
            while (k < n && target[k] == '_') k++;

            // If both indices are out of bounds, we are done.
            if (j == n && k == n) break;

            // If one index is out of bounds or characters don't match, return false.
            if (j == n || k == n || start[j] != target[k]) return false;

            // Positional constraints:
            // 'L' can only move left, so its index in `start` must be >= in `target`.
            // 'R' can only move right, so its index in `start` must be <= in `target`.
            if ((start[j] == 'L' && j < k) || (start[j] == 'R' && j > k)) {
                return false;
            }

            j++;
            k++;
        }
  

        return true;
    }
};
