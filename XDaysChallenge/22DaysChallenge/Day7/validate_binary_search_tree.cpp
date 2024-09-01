// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Question requires only understanding of recursion.
*/
class Solution {
public:
    bool helper(TreeNode* root) {
        if(!root) return true;
        if(root->left && root->left->val>=root->val) return false;
        if(root->right && root->right->val<=root->val) return false;
        return helper(root->left) && helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};