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
    void helper(TreeNode* root, int targetSum, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) {
            return;
        }

        // Add the current node to the path
        path.push_back(root->val);
        sum += root->val;

        // Check if it's a leaf node and the path sum equals the target sum
        if (!root->left && !root->right && sum == targetSum) {
            ans.push_back(path);
        }

        // Recur for left and right subtrees
        helper(root->left, targetSum, sum, path, ans);
        helper(root->right, targetSum, sum, path, ans);

        // Backtrack: Remove the current node from the path
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root, targetSum, 0, path, ans);
        return ans;
    }
};


 

  