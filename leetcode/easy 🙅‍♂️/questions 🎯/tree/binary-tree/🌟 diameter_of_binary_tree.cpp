// https://leetcode.com/problems/diameter-of-binary-tree/

/**
 * LOGIC: Basic recursive solution
 * 
 */ 
class Solution {
public:
    int helper(TreeNode* root, int& res) {
        if(!root) return 0;
        int leftDepth = helper(root->left, res);
        int rightDepth = helper(root->right, res);
        int currDia = leftDepth + rightDepth;
        if(currDia>res) {
            res=currDia;
        }
        return max(leftDepth, rightDepth) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int result=0;
        helper(root, result);
        return result;
    }
};