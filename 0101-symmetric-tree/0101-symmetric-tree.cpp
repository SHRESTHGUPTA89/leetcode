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
    // Helper function to check if two subtrees are mirror images
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both nodes are NULL, this is symmetric
        if (left == NULL && right == NULL) return true;
        
        // If only one of the nodes is NULL, it's not symmetric
        if (left == NULL || right == NULL) return false;
        
        // If the values of the nodes are different, it's not symmetric
        if (left->val != right->val) return false;
        
        // Recursively check the subtrees
        // Left subtree of left node should be a mirror of right subtree of right node
        // Right subtree of left node should be a mirror of left subtree of right node
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    
    // Main function to check if the tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // If the tree is empty, it's symmetric
        if (root == NULL) return true;
        
        // Use the helper function to check if the left and right subtrees are mirrors
        return isMirror(root->left, root->right);
    }
};
