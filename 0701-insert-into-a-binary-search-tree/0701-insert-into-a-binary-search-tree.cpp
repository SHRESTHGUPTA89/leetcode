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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root is null, create a new node and return it as the root
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        // Traverse the tree to find the correct position
        if (val < root->val) {
            // Insert into the left subtree
            root->left = insertIntoBST(root->left, val);
        } else {
            // Insert into the right subtree
            root->right = insertIntoBST(root->right, val);
        }
        
        // Return the unchanged root
        return root;
    }
};
