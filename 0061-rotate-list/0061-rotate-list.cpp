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
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: if the list is empty or has only one node, or no rotation is needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Find the length of the list and make it circular
        ListNode* tail = head;
        int n = 1;  // Length of the list (starting at 1 because we are at the head)
        
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Connect the tail to the head to form a circular list
        tail->next = head;

        // Step 2: Normalize k to be within the range of the list length
        k = k % n;
        
        // Step 3: Find the new tail: (n - k)th node
        // Traverse to the new tail node, which is (n - k)th from the beginning
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        // Step 4: The new head is the node after the new tail
        ListNode* newHead = newTail->next;
        
        // Step 5: Break the circular list
        newTail->next = nullptr;
        
        // Return the new head of the list
        return newHead;
    }
};
