// https://binarysearch.com/problems/Twin-Trees

/**
 * LOGIC: Basic tree/recursion question
 * 
 * 
 * 
 */ 
bool solve(Tree* root0, Tree* root1) {
    if(!root0 && !root1)  return true;
    if((root0 && !root1) || 
    (!root0 && root1) ||
    (root0->val!=root1->val)) {
        return false;
    }
    bool left = solve(root0->left, root1->left);
    bool right = solve(root0->right, root1->right);
    return left && right;
}