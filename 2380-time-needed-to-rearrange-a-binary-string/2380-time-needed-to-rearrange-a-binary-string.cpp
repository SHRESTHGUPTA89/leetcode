#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int seconds = 0;

        while (s.find("01") != string::npos) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    i++;  // Skip the next index as we just swapped
                }
            }
            seconds++;
        }

        return seconds;
    }
};
