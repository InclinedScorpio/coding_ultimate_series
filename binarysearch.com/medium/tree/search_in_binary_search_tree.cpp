// https://binarysearch.com/problems/Search-in-a-Binary-Search-Tree

/**
 * LOGIC: Basic recursion & logic of BST!
 * 
 * COMPLEXITY: O(logN)
 */ 

bool solve(Tree* root, int val) {
    if(!root) return false;
    if(root->val == val) {
        return true;
    } else if(root->val > val) {
        return solve(root->left, val);
    } else {
        return solve(root->right, val);
    }
}