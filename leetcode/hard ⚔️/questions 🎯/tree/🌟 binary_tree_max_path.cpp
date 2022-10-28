// https://leetcode.com/problems/binary-tree-maximum-path-sum/


/**
 * LOGIC: Basic problem.
 *
 */
class Solution {
public:
    int helper(TreeNode* root, int& maxVal) {
        if(!root) return 0;
        
        int leftSum = helper(root->left, maxVal);
        if((leftSum + root->val) < root->val) leftSum = 0;
        int rightSum = helper(root->right, maxVal);
        if((rightSum + root->val) < root->val) rightSum = 0;
        
        if(maxVal<(leftSum+rightSum+root->val)) 
            maxVal = leftSum + rightSum + root->val;
        
        return  max(leftSum, rightSum) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxVal=INT_MIN;
        helper(root, maxVal);
        return maxVal;
    }
};