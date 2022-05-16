// https://binarysearch.com/problems/Tree-Pruning

/**
 * LOGIC: Basic recursion
 * - Only point is to understand that tree works on pointer
 * - So if in helper method we remove connections
 * - That would reflect in solve method root (as it's pointer)
 * 
 */ 
bool helper(Tree* root) {
    if(!root) return true;
    
    bool left = helper(root->left);
    if(left) {
        root->left = NULL;
    }
    
    bool right = helper(root->right);
    if(right) {
        root->right = NULL;
    }

    if(root->val==0 && left && right) {
        return true;
    }

    return false;
}

Tree* solve(Tree* root) {
    helper(root);
    return root;
}