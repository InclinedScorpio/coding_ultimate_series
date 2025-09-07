// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=problem-list-v2&envId=plakya4j

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
        int helper(TreeNode* root, int maxTillNow) {
            if(!root) return 0;
            int res=0;
            res+=helper(root->left, max(maxTillNow, root->val));
            res+=helper(root->right, max(maxTillNow, root->val));
            if(maxTillNow<=root->val) return res+1;
            return res;
        }
    
        int goodNodes(TreeNode* root) {
            if(!root) return 0;
            return helper(root->left, root->val) + helper(root->right, root->val) + 1;
        }
    };