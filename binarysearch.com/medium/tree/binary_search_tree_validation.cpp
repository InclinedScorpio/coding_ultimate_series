// https://binarysearch.com/problems/Binary-Search-Tree-Validation


/**
 * LOGIC: Basic recursion
 * - Point to note is while recursion we need to send the minPossible, maxPossible num
 * 
 */ 
bool helper(Tree* root, int minPossible=INT_MIN, int maxPossible=INT_MAX) {
    if(!root) return true;

    if(root->val < minPossible || root->val > maxPossible) {
        return false;
    }

    bool left = helper(root->left, minPossible, root->val);
    bool right = helper(root->right, root->val, maxPossible);
    return left&&right;
}


bool solve(Tree* root) {
    return helper(root);
}