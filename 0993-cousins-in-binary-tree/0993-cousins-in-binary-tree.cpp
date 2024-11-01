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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr || root->val == x || root->val == y)
            return false;
        
        int xParent = -1, yParent = -1;
        int xHeight = findHeightAndParent(root, x, 0, xParent);
        int yHeight = findHeightAndParent(root, y, 0, yParent);
        
        // Nodes are cousins if they are at the same height but have different parents
        return (xHeight == yHeight) && (xParent != yParent);
    }
    
private:
    int findHeightAndParent(TreeNode* node, int val, int height, int& parent) {
        if (node == nullptr) return -1;
        
        if ((node->left && node->left->val == val) || (node->right && node->right->val == val)) {
            parent = node->val;
            return height + 1;
        }
        
        int leftHeight = findHeightAndParent(node->left, val, height + 1, parent);
        if (leftHeight != -1) return leftHeight;
        
        return findHeightAndParent(node->right, val, height + 1, parent);
    }
};
