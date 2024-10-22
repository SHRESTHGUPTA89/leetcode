#include <vector>
#include <queue>
#include <numeric> // for accumulate
#include <algorithm> // for sort
using namespace std;

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0; // Handle empty tree case
        }
        
        vector<long long> levelSums; // To store the sum of each level
        
        queue<TreeNode*> q;
        q.push(root);
        
        // BFS traversal to compute the sum of each level
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val; // Sum the values at this level
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            levelSums.push_back(levelSum); // Store the sum for this level
        }
        
        // Sort the level sums in descending order to find the Kth largest
        sort(levelSums.begin(), levelSums.end(), greater<long long>());
        
        // Check if k is within the bounds of the number of levels
        if (k > levelSums.size()) {
            return -1; // If k is larger than the number of levels, return an error value
        }
        
        return levelSums[k - 1]; // Return the Kth largest sum (1-based index)
    }
};
