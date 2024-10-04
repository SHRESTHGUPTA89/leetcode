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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                
                // Connect the right subtree to the rightmost node of the left subtree
                pre->right = curr->right;
                
                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            // Move to the right subtree (which now includes the flattened left subtree)
            curr = curr->right;
        }
    }
};
