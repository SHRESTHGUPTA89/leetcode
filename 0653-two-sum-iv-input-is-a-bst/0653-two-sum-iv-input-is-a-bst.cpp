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
    
    void inorder(TreeNode* root ,   vector<int> &v){
        
        if(!root){
            return;
        }
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
        
    }
    bool findTarget(TreeNode* root, int k) {
        
        
        // method 1 here we use inorder to make it sorted array than use simple to pointer 
        
        vector<int>v;
        // v will be in sorted order , because inorder of BST is sorted 
        inorder(root, v);
        
        
        int l=0;
        int r=v.size()-1;
        
        while(l<r){
            int sum=v[l]+v[r];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                l++;
            }
            else{
                r--;
            }
            
        }
        
        return false;
    }
};













   