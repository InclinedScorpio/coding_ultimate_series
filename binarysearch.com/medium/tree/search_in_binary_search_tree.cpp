

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