// https://leetcode.com/problems/path-sum/

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

/**
 * LOGIC: keep decreasing the target and check if it's 0 at leaf node (Path found)
 * - Rest basic remains same 3 point - 1.edge case, 2.recursive call, 3.operations
 * 
 */ 
class Solution {
public:
    bool utilityMethod(TreeNode* root, int targetSum) {
        if(!root) {
            return false;
        }
        targetSum=targetSum - root->val;
        if(!root->left && !root->right && targetSum==0) {
            return true;
        }
        bool leftRes = utilityMethod(root->left, targetSum);
        if(leftRes) {
            return true;
        }
        bool rightRes = utilityMethod(root->right, targetSum);
        return leftRes || rightRes;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return utilityMethod(root, targetSum);
    }
};