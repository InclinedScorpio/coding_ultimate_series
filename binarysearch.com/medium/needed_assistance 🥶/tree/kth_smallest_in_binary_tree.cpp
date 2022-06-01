// https://binarysearch.com/problems/Kth-Smallest-in-a-Binary-Search-Tree

/**
 * 
 * LOGIC: Point to note is:
 * - Use global variable whenever required
 * - Use by reference whenever required
 * 
 * - Rest is basic, it's Inorder traversal!
 * 
 */

int maxRes;

void helper(Tree* root, int &k) {
    if(!root) return;

    helper(root->left, k);
    if(k==0) maxRes = root->val;
    k--;
    helper(root->right, k);
}

int solve(Tree* root, int k) {
    helper(root, k);
    return maxRes;
}