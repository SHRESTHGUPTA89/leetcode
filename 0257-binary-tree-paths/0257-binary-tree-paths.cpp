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
    // Helper function to find all paths
    void treepath(TreeNode* root, string path, vector<string>& ans) {
        if (root == nullptr) return;

        // Add current node's value to the path
        path += to_string(root->val);

        // If it's a leaf node, add the path to the result
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        } else {
            // Add the "->" before exploring the child nodes
            path += "->";
            if (root->left) {
                treepath(root->left, path, ans);
            }
            if (root->right) {
                treepath(root->right, path, ans);
            }
        }
    }

    // Main function to generate binary tree paths
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        treepath(root, path, ans);
        return ans;
    }
};
















