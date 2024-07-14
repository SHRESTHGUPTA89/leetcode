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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());
        ListNode ans(0);
        ans.next = head;
        ListNode* current = &ans;
        while (current->next != nullptr) {
            if (s.find(current->next->val) != s.end()) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return ans.next;
    }
    // tc - O(l*logn)
    // sc - O(n)
};