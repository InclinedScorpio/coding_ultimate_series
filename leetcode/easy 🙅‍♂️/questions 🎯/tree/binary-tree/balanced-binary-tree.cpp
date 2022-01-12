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


/**
 * LOGIC: More than 1 thing can be returned from recursion.
 * 
 * - For base condition return back
 * - There are generally 3 steps in recursion - base condition, next call, some calculation and return
 * 
 * 
 * /
struct TreeData {
    int height;
    bool isBalanced;
};

class Solution {
public:
    
    TreeData iterateAndCheck(TreeNode* root) {
	    // null must return height 0 and it will be obviously balanced on leaf node so {0, true}
        if(root==NULL) {
            struct TreeData rootCase = {0, true};
            return rootCase;
        }
	    // keep calling left and right nodes & return struct which must carry height and isBalanced
        TreeData leftHeight = iterateAndCheck(root->left);
        TreeData rightHeight = iterateAndCheck(root->right);
		
		// if left or right gives isBalanced as false - just return back (no one cares about int in this problem so kept 0)
        if(!leftHeight.isBalanced || !rightHeight.isBalanced) {
            return {0, false};
        }
		
		// if reached here, evaluate the height and if height > 1
        struct TreeData newTreeData;
        newTreeData.height = max(leftHeight.height, rightHeight.height) + 1;
        newTreeData.isBalanced = abs(leftHeight.height-rightHeight.height) > 1 ? false : true;
        return newTreeData;
    }
    
    bool isBalanced(TreeNode* root) {
        return iterateAndCheck(root).isBalanced;
    }
};