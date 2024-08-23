#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Step 2: Use a priority queue to store characters sorted by frequency
        priority_queue<pair<int, char>> maxHeap;
        for (auto &entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        // Step 3: Build the result string
        string result = "";
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            result.append(top.first, top.second);  // Append the character 'top.first' times
        }

        return result;
    }
};