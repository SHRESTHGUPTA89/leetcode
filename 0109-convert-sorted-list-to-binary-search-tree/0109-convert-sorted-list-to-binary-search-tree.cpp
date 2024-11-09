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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case: if head is null, return null
        if (head == nullptr) {
            return nullptr;
        }
        // If there's only one node, it becomes the root of the subtree
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        // Initialize slow and fast pointers, with slow_prev to track node before middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = nullptr;

        // Find the middle node in the list (using slow/fast pointers)
        while (fast != nullptr && fast->next != nullptr) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect the left half from the middle node
        if (slow_prev != nullptr) {
            slow_prev->next = nullptr;
        }

        // The middle node becomes the root
        TreeNode* root = new TreeNode(slow->val);

        // Recursively build the left and right subtrees
        root->left = sortedListToBST(head);        // Left subtree from head to slow_prev
        root->right = sortedListToBST(slow->next); // Right subtree from slow->next to end

        return root;
    }
};
