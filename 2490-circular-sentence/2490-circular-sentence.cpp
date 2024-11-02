#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        // Check if sentence has only one word
        if (n == 0 || sentence[0] != sentence[n - 1]) 
            return false;

        // Traverse sentence and check word boundaries
        for (int i = 1; i < n - 1; i++) {
            // Check if there is a space and the end of one word matches the start of the next
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
