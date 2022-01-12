// https://leetcode.com/problems/balanced-binary-tree/

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

struct TreeData {
    int height;
    bool isBalanced;
};

class Solution {
public:
    
    TreeData iterateAndCheck(TreeNode* root) {
        if(root==NULL) {
            struct TreeData rootCase = {0, true};
            return rootCase;
        }
        TreeData leftHeight = iterateAndCheck(root->left);
        TreeData rightHeight = iterateAndCheck(root->right);
        if(!leftHeight.isBalanced || !rightHeight.isBalanced) {
            return {0, false};
        }
        struct TreeData newTreeData;
        newTreeData.height = max(leftHeight.height, rightHeight.height) + 1;
        newTreeData.isBalanced = abs(leftHeight.height-rightHeight.height) > 1 ? false : true;
        return newTreeData;
    }
    
    bool isBalanced(TreeNode* root) {
        return iterateAndCheck(root).isBalanced;
    }
};