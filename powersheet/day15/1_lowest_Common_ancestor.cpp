// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) {
            return root;
        }

        TreeNode* returnThis=NULL;
        if(p==root) {
            return p;
        }
        if(q==root) {
            return q;
        }

        if(left) return left;
        if(right) return right;
        return NULL;
    }
};