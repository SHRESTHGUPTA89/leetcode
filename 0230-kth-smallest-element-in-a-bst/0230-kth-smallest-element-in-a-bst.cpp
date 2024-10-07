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
    int kthSmallest(TreeNode* root, int k) {
        // Helper function to perform in-order traversal
        return inorder(root, k);
    }
    
    // Helper function to perform in-order traversal and find the k-th smallest
    int inorder(TreeNode* node, int& k) {
        if (!node) return -1;  // Base case: if node is null, return an invalid result
        
        // Traverse the left subtree
        int left = inorder(node->left, k);
        if (left != -1) return left;  // If we found the k-th element in the left subtree, return it
        
        // Process the current node
        k--;  // Decrement k (we found one more node in order)
        if (k == 0) return node->val;  // If k reaches 0, we found the k-th smallest element
        
        // Traverse the right subtree
        return inorder(node->right, k);
    }
};
