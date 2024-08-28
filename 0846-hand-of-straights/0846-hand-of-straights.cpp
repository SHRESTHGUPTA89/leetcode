#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Frequency map to count occurrences of each card
        std::unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Sort the hand to process cards in increasing order
        std::sort(hand.begin(), hand.end());

        // Attempt to form groups
        for (int card : hand) {
            if (count[card] == 0) {
                continue; // Skip if this card has already been used
            }

            // Try to form a group starting with 'card'
            for (int i = 0; i < groupSize; ++i) {
                if (count[card + i] == 0) {
                    return false; // If any card in the group is missing, return false
                }
                count[card + i]--; // Decrement the count of each card in the group
            }
        }

        return true; // All cards have been successfully grouped
    }
};

