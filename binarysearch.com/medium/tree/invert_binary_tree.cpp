// https://binarysearch.com/problems/Invert-Tree

/**
 * LOGIC: Basic recursion, nothing else
 * 
 */ 
Tree* solve(Tree* root) {
    if(!root) return NULL;
    Tree* right = root->right;
    root->right = root->left;
    root->left = right;
    solve(root->left);
    solve(root->right);
    return root;
}