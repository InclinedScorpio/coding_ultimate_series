// https://leetcode.com/problems/validate-binary-search-tree/description/

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

    bool helper(TreeNode* root, pair<long, long> inbtw) {
        if(!root)return true;

        if(root->val>inbtw.first && root->val<inbtw.second)  {
            return helper(root->left, {inbtw.first, root->val}) && helper(root->right, {root->val, inbtw.second});
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        if(root && !root->left && !root->right)  return true;
        return this->helper(root, {LONG_MIN, LONG_MAX});
    }
};