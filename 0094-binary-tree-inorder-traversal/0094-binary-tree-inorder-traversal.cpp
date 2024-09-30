class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (current->left == nullptr) {
                // No left subtree, visit the current node
                result.push_back(current->val);
                // Move to the right subtree
                current = current->right;
            } else {
                // Find the predecessor (rightmost node in the left subtree)
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                
                // Create a temporary link from predecessor to current
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    // Move to the left subtree
                    current = current->left;
                } 
                // Revert the changes (remove temporary link) and visit current node
                else {
                    predecessor->right = nullptr;
                    result.push_back(current->val);
                    // Move to the right subtree
                    current = current->right;
                }
            }
        }
        
        return result;
    }
};
