#include <queue>
#include <utility> // For std::pair

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue will store pairs of (node, index)
        std::queue<std::pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;

            maxWidth = std::max(maxWidth, int(end - start + 1));

            for (int i = 0; i < levelSize; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize the index by subtracting the start index
                unsigned long long normalizedIndex = index - start;

                if (node->left) {
                    q.push({node->left, 2 * normalizedIndex + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalizedIndex + 2});
                }
            }
        }

        return maxWidth;
    }
};
