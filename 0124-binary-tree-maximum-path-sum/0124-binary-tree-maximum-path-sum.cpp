class Solution {
public:
    int globalMax = INT_MIN; // To store the global maximum path sum
    
    // Helper function to calculate the maximum gain from each subtree
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Base case: return 0 if the node is null
        }
        
        // Recursively get the maximum gain from the left and right subtrees
        // If a subtree's gain is negative, we take 0 (ignore that subtree)
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        // Calculate the maximum path sum that passes through the current node
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the global maximum if the current path sum is larger
        globalMax = max(globalMax, currentPathSum);
        
        // Return the maximum gain that the current node can contribute to its parent
        return node->val + max(leftGain, rightGain);
    }
    
    int maxPathSum(TreeNode* root) {
        maxGain(root); // Start the recursion from the root node
        return globalMax; // Return the global maximum path sum
    }
};
