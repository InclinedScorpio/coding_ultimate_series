// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
 * LOGIC: Iterative approach 3 things - edge case, iterate, operation
 * - operation is what we need to understand.
 * 
 */ 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return 1;
        }
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if(minLeft==0) {
            return minRight+1;
        }
        if(minRight==0) {
            return minLeft+1;
        }
        return min(minLeft, minRight) + 1;
    }
};