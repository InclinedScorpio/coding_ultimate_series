// https://binarysearch.com/problems/Largest-Root-to-Leaf-Sum

/**
 * LOGIC: Basic recursion
 * 
 */ 
int solve(Tree* root) {
    if(!root) return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    return max(left, right) + root->val;
}