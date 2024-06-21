class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int alwaysSatisfied = 0;  // Customers who are always satisfied (when owner is not grumpy)
        int extraSatisfaction = 0;  // Extra satisfaction by making the owner not grumpy for `minutes` minutes
        int maxExtraSatisfaction = 0;  // Max extra satisfaction we can achieve in any window of `minutes`

        // Calculate the initial satisfaction and the extra satisfaction in the first window
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                alwaysSatisfied += customers[i];
            } else if (i < minutes) {
                extraSatisfaction += customers[i];
            }
        }

        maxExtraSatisfaction = extraSatisfaction;

        // Slide the window and calculate the maximum possible extra satisfaction
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                extraSatisfaction += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                extraSatisfaction -= customers[i - minutes];
            }
            maxExtraSatisfaction = max(maxExtraSatisfaction, extraSatisfaction);
        }

        return alwaysSatisfied + maxExtraSatisfaction;
    }
};
















        
        