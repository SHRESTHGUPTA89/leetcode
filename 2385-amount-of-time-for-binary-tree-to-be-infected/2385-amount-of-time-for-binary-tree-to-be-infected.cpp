#include <unordered_map>
#include <queue>

class Solution {
public:
    // Helper function to build the graph (adjacency list) from the tree
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        if (node == nullptr) return;
        
        // If there is a parent, create a bidirectional edge
        if (parent != nullptr) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }
        
        // Recur for left and right children
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
    
    // Main function to compute the amount of time to infect the whole tree
    int amountOfTime(TreeNode* root, int start) {
        // Step 1: Build the graph representation of the tree
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);
        
        // Step 2: Perform BFS from the start node to simulate the infection spreading
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(start);
        visited[start] = true;
        int time = -1;  // Start at -1 because the first loop will add 1 right away
        
        while (!q.empty()) {
            int size = q.size();
            time++;
            
            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();
                
                // For each neighbor (in the graph), if not visited, mark as visited and add to queue
                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return time;
    }
};
