#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        // If the total number of cards is not a multiple of groupSize, we can't divide them into groups.
        if (hand.size() % groupSize != 0) return false;

        // Use a map to count the frequency of each card.
        std::map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Iterate through the sorted keys in the map.
        for (auto it = count.begin(); it != count.end(); ++it) {
            // The current card value and its count.
            int card = it->first;
            int cardCount = it->second;

            // If there are any cards of this value left to process.
            if (cardCount > 0) {
                // We need to form groups starting with this card.
                for (int i = 0; i < groupSize; ++i) {
                    // Check if the group can be formed.
                    if (count[card + i] < cardCount) {
                        return false; // Not enough cards to form a group.
                    }
                    // Reduce the count of the card used in forming the group.
                    count[card + i] -= cardCount;
                }
            }
        }

        return true; // Successfully formed all groups.
    }
};
