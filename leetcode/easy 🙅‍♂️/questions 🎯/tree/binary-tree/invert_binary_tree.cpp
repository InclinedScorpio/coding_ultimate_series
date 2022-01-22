// https://leetcode.com/problems/invert-binary-tree/

/**
 * LOGIC: Basic
 * - Just reverse the pointers by DFS!
 * 
 */ 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
};