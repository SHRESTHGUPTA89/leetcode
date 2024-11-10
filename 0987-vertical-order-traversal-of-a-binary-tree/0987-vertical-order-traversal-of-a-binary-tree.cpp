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
        // Map to store nodes based on vertical distance and level
        // map<vertical, map<level, multiset<node values>>>
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue to perform BFS
        // Each element in the queue stores {node, vertical distance, level}
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // Start with root at vertical 0, level 0
        
        // Perform BFS
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            
            // Store the node's value in the map
            nodes[vertical][level].insert(node->val);
            
            // If the node has a left child, go to vertical-1 and level+1
            if (node->left) {
                todo.push({node->left, {vertical - 1, level + 1}});
            }
            
            // If the node has a right child, go to vertical+1 and level+1
            if (node->right) {
                todo.push({node->right, {vertical + 1, level + 1}});
            }
        }
        
        // Prepare the result
        vector<vector<int>> result;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                // Insert all the nodes in the current vertical and level
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};