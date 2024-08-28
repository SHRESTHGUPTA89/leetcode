#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Create a frequency map to count the occurrences of each task
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }

        // Step 2: Use a max heap to store the frequencies (max heap prioritizes tasks with higher frequencies)
        priority_queue<int> maxHeap;
        for (auto it : taskCount) {
            maxHeap.push(it.second);
        }

        // Step 3: Initialize the time counter
        int time = 0;

        // Step 4: Process the tasks in cycles of (n + 1)
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = 0;

            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    temp.push_back(maxHeap.top() - 1);
                    maxHeap.pop();
                    cycle++;
                }
            }

            // Step 5: Push remaining tasks back into the heap
            for (int count : temp) {
                if (count > 0) {
                    maxHeap.push(count);
                }
            }

            // Step 6: Add the time required for this cycle to the total time
            time += maxHeap.empty() ? cycle : n + 1;
        }

        // Step 7: Return the total time
        return time;
    }
};
