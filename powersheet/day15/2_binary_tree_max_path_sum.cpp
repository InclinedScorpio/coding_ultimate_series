// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

    int maxSum=INT_MIN;

    int helper(TreeNode* root) {
        if(!root) return 0;
        int left = helper(root->left);

        int right = helper(root->right);

        int maxCheck = max(left + right + root->val, max(left+root->val, right+root->val));
        this->maxSum = max(maxCheck, this->maxSum);
        this->maxSum = max(this->maxSum, root->val);

        return max(left+root->val, max(root->val, right+root->val));
    }


    int maxPathSum(TreeNode* root) {
        this->helper(root);
        return maxSum;
    }
};