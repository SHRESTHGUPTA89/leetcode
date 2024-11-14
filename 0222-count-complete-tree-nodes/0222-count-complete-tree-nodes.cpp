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
    
    int count_inorder(TreeNode* root) {
        if (!root) {
            return 0;
        }

        
        int leftCount = count_inorder(root->left);
        int rightCount = count_inorder(root->right);

        return leftCount + rightCount + 1;
    }

    int countNodes(TreeNode* root) {
        return count_inorder(root);
    }
};
