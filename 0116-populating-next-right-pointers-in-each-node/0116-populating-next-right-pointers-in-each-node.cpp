class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;  // Base case: empty tree
        
        Node* level_start = root;  // Start from the root (level 0)
        
        while (level_start->left != nullptr) {  // While there is a next level
            Node* current = level_start;  // Iterate over the current level
            
            while (current != nullptr) {
                // Connect the left child to the right child
                current->left->next = current->right;
                
                // Connect the right child to the next node's left child (if exists)
                if (current->next != nullptr) {
                    current->right->next = current->next->left;
                }
                
                // Move to the next node in the current level
                current = current->next;
            }
            
            // Move to the next level (leftmost node of the next level)
            level_start = level_start->left;
        }
        
        return root;
    }
};
