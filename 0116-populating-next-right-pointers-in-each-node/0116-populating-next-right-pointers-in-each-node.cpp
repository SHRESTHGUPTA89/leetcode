#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;  // Base case: empty tree

        std::queue<Node*> q;
        q.push(root);  // Start with the root node

        // BFS (level-order traversal)
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at the current level
            
            // Traverse the nodes at this level
            for (int i = 0; i < size; i++) {
                Node* current = q.front();  // Get the front node
                q.pop();
                
                // Set the `next` pointer of the current node
                if (i < size - 1) {
                    current->next = q.front();  // Connect to the next node in the queue
                } else {
                    current->next = nullptr;  // Last node of this level points to NULL
                }
                
                // Push the children of the current node into the queue
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }
        }
        
        return root;  // Return the modified tree
    }
};
