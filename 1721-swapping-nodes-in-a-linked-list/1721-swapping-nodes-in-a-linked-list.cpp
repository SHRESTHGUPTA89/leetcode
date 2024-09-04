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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* first = nullptr;
        ListNode* current = head;
        int length = 0;
        
        while (current != nullptr) {
            length++;
            if (length == k) {
                first = current;
            }
            current = current->next;
        }
        
        
        int indexFromStart = length - k + 1;
        current = head;
        ListNode* second = nullptr;
        for (int i = 1; i <= indexFromStart; ++i) {
            if (i == indexFromStart) {
                second = current;
            }
            current = current->next;
        }
        

        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
        
        return head;
    }
};
