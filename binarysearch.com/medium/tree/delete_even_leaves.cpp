// https://binarysearch.com/problems/Delete-Even-Leaves

/**
 * LOGIC: Basic recursion
 * - Just replace left and right with the new values coming
 * - The new value can be null as well based on given question condition is returned
 * 
 */ 
Tree* solve(Tree* root) {
    if(!root) return NULL;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(!root->left && !root->right && root->val%2==0) return NULL;
    return root;
}