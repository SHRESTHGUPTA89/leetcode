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
    // Function to calculate GCD using Euclidean algorithm
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr) {
            // Calculate GCD of slow->val and fast->val
            int gcdValue = gcd(slow->val, fast->val);
            
            // Insert new node with GCD value between slow and fast
            ListNode* add = new ListNode(gcdValue);
            slow->next = add;
            add->next = fast;
            
            // Move slow and fast to the next pair
            slow = fast;
            fast = fast->next;
        }
        
        return head;
    }
};
