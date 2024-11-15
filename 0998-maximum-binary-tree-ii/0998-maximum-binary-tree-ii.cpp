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
    void inorder(TreeNode* root , vector<int>&v){
        if(!root){
            return;
        }
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
    }
    TreeNode* helper(vector<int>& nums, int s, int e) {
        if (s > e) {
            return nullptr;
        }
        
        
        int maxIndex = s;
        for (int i = s; i <= e; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        
        
        TreeNode* root = new TreeNode(nums[maxIndex]);
        
        
        root->left = helper(nums, s, maxIndex - 1);
        root->right = helper(nums, maxIndex + 1, e);
        
        return root;
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        vector<int>v;
        
        inorder(root,v);
        
        v.push_back(val);
        
        return helper(v, 0, v.size() - 1);
        
    }
};


    
   