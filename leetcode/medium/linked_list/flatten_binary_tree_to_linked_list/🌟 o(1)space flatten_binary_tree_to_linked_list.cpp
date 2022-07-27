// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * LOGIC: Think about it, as we are given that as per preorder we need to align the nodes to skewed right...
 * - That means we need to visit recurse(left, right's) end and then see if any single node on left? If yes bring it to right while pushing existing right things to end of lefts end
 * - Above line is important
 * 
 * - We need to understand the atomic problem - rest is same recursion
 * - Hence as we shift the left part to right, we change left to NULL and the small part is now right skewed
 * - As we go back we again check if anything present in left!
 * - If yes, our motive is always that to bring it to immediate right of current node while pushing things on right to below! Why? because preorder needed!
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(1)
 * 
 */ 
class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* leftOne = helper(root->left);
        TreeNode* rightOne = helper(root->right);
        
        if(leftOne) {
            TreeNode* saveRight = root->right;

            root->right = root->left;
            root->left = NULL;
            // iterate and reach last
            TreeNode* iter = root;
            while(iter->right) {
                iter = iter->right;
            }
            iter->right = saveRight;
        }
        return root;
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};