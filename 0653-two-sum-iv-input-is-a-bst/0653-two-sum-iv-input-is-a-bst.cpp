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
    
    bool seen(TreeNode* root, int k, unordered_set<int>& s) {
        if (!root) {
            return false;
        }
        
        
        if (s.count(k - root->val)) {
            return true;
        }
        
    
        s.insert(root->val);
        
        
        return seen(root->left, k, s) || seen(root->right, k, s);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return seen(root, k, s);
    }
};
