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
        flatNode(root, nullptr);
    }

    TreeNode *flatNode(TreeNode* cur, TreeNode *pre) {
        if(cur == nullptr) {
            return pre;
        }

        TreeNode *right = cur->right;
        if(pre != nullptr) {
            pre->left = nullptr;
            pre->right = cur;
        }
        
        cur = flatNode(cur->left, cur);
        cur = flatNode(right, cur);
        return cur;
    }
};