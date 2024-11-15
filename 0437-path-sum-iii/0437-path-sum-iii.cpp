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
    // Helper function to calculate the number of paths with sum starting from `node`
    int pathFromNode(TreeNode* node, int targetSum, long long currentSum) {
        if (!node) {
            return 0;
        }

        currentSum += node->val;

        // Check if the current path sum equals targetSum
        int count = (currentSum == targetSum) ? 1 : 0;

        // Recur for left and right children
        count += pathFromNode(node->left, targetSum, currentSum);
        count += pathFromNode(node->right, targetSum, currentSum);

        return count;
    }

    // Main function to count all paths in the tree
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }

        // Count paths starting from the current node
        int count = pathFromNode(root, targetSum, 0);

        // Recur for left and right subtrees
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};
