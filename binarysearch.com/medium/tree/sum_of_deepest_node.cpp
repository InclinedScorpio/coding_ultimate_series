// https://binarysearch.com/problems/Sum-of-the-Deepest-Nodes

/**
 * LOGIC: Basic recursion
 * - Must know to return struct!
 * 
 */ 

 struct Res {
     int depth; int value;
 };

Res helper(Tree* root, int height) {
    if(!root) {
        return {0, 0};
    }
    if(!root->left && !root->right) {
        return {height, root->val};
    }
    Res left = helper(root->left, height+1);
    Res right = helper(root->right, height+1);
    if(left.depth==right.depth) {
        return {left.depth, left.value+right.value};
    }
    Res res = left.depth>right.depth?left: right;
    return {res.depth, res.value};
}

int solve(Tree* root) {
    if(!root) return 0;
    return helper(root, 0).value;
}