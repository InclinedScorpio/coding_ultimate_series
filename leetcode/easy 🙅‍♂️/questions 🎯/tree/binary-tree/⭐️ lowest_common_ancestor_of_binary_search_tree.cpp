// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * LOGIC: Basic, just keep a pointer checking the number of nodes found
 * 
 */ 
class Solution {
public:
    TreeNode* ss=NULL;
    int helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* result) {
        if(!root) return 0;
        int res = helper(root->left, p, q, result) + helper(root->right, p, q, result);
        if(root==p || root==q)  res++;

        if(res==2 && !ss) {
            result = root;
            ss=root;
            return 3;
        }
        return res;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result=NULL;
        helper(root, p, q, result);
        return ss;
    }
};