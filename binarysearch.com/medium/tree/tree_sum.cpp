// https://binarysearch.com/problems/Tree-Sum

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int solveSum(Tree* root) {
   if(!root) return 0;
    int left = solveSum(root->left);
    int right = solveSum(root->right);
    return left+right+root->val;
}
int solve(Tree* root) {
 return solveSum(root);
}