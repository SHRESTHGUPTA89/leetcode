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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Process the current node and move to the right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor of the current node
                pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }
                
                // Set up the thread (temporary right link)
                if (pre->right == nullptr) {
                    pre->right = curr;
                    result.push_back(curr->val); // Process the current node before moving left
                    curr = curr->left;
                } else {
                    // Remove the thread (restore the original tree structure)
                    pre->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};

