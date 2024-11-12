/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes left
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) return head;  // If less than k nodes, return head
            node = node->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Recur for the remaining list and link the two parts
        if (next) {
            head->next = reverseKGroup(next, k);
        }

        // Step 4: Return the new head of the reversed list
        return prev;
    }
};
