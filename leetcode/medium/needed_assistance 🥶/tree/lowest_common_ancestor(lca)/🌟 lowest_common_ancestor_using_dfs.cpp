// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * QUESTION: Find common lowest Ancestor (lowest doesn't mean smallest in value -_-)
 * LOGIC: Note- all the val's are unique
 * - Hence we just need to find the num and return as soon as get
 * - If at any instance we see both left and right carrying value we will return back the current node
 * - because that's the node which is commong lowest ancestor
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode* left = helper(root->left, p, q);
        TreeNode* right = helper(root->right, p, q);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};