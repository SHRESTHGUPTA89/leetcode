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
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, 
                              vector<int>& postorder, int& postIndex, 
                              unordered_map<int, int>& inMap) {
        // Base case: if there are no elements to process
        if (inStart > inEnd) {
            return nullptr;
        }

        // Get the root node with the current postorder element
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Root splits inorder list into left and right subtrees
        int inIndex = inMap[rootVal];

        // Recursively build the right and left subtrees
        root->right = buildTreeHelper(inorder, inIndex + 1, inEnd, postorder, postIndex, inMap);
        root->left = buildTreeHelper(inorder, inStart, inIndex - 1, postorder, postIndex, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;  // Start from the last element in postorder
        unordered_map<int, int> inMap;  // Map to store the index of each value in inorder

        // Populate the map with inorder indices
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, postIndex, inMap);
    }
};
