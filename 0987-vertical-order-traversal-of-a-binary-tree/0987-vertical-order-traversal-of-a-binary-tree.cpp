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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes based on level distance and vertical
        // map<level, map<vertical, multiset<node values>>>
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue to perform BFS
        // Each element in the queue stores {node, level distance, vertical}
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // Start with root at level 0, vertical 0
        
        // Perform BFS
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int level = p.second.first;
            int vertical = p.second.second;
            
            // Store the node's value in the map
            nodes[level][vertical].insert(node->val);
            
            // If the node has a left child, go to level-1 and vertical+1
            if (node->left) {
                todo.push({node->left, {level - 1, vertical + 1}});
            }
            
            // If the node has a right child, go to level+1 and vertical+1
            if (node->right) {
                todo.push({node->right, {level + 1, vertical + 1}});
            }
        }
        
        // Prepare the result
        vector<vector<int>> result;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                // Insert all the nodes in the current level and vertical
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};
