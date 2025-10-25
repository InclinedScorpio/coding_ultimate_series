//https://leetcode.com/problems/subtree-of-another-tree/description/?envType=problem-list-v2&envId=e915v4g6

/**
 * Problem requires understanding of recursion and tree traversal
 * 
 * 
 */
class Solution {
public:
    bool checkSameStructure(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot->val) return false;
        bool left = checkSameStructure(root->left, subRoot->left);
        bool right = checkSameStructure(root->right, subRoot->right);
        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val) {
            if(checkSameStructure(root, subRoot)) return true;
        }
        if(isSubtree(root->left, subRoot)) return true;
        if(isSubtree(root->right, subRoot)) return true;
        return false;
    }
};