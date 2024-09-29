class Solution {
public:
    // Helper function to construct BST recursively
    TreeNode* constructBST(vector<int>& preorder, int& index, int bound) {
        // If all elements are processed or the current value exceeds the bound, return NULL
        if (index == preorder.size() || preorder[index] > bound) {
            return nullptr;
        }
        
        // Create the current node with the value at 'index'
        TreeNode* root = new TreeNode(preorder[index++]);
        
        // Recursively build the left subtree, setting the bound to the root's value
        root->left = constructBST(preorder, index, root->val);
        
        // Recursively build the right subtree, keeping the bound the same
        root->right = constructBST(preorder, index, bound);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return constructBST(preorder, index, INT_MAX);
    }
};
