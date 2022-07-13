// https://binarysearch.com/problems/Complete-Binary-Tree

/**
 * LOGIC: Main logic is to understand what is complete binary tree is
 * - A complete binary tree must have 2 children, except of last row (can have 0 or 1)
 * - Also the filling of nodes must be from left to right
 * - So that means if on extreme left at last level there is one node, then no node must be there on right side of that level except immediate right of that node 
 * 
 * COMPLEXITY: O(N)
 * 
 */

 struct Store {
    int height;
    bool result;
 };

Store helper(Tree* root, bool& canHaveOne) {
    if(!root) return {0, true};
    if(root->right && !root->left) return { -1, false};

    if(!root->right && root->left && root->left->left) return {-1, false};

    if(!canHaveOne && root->left && !root->right) return {-1, false};
    if(canHaveOne && root->left && !root->right) canHaveOne = false;

    Store res = helper(root->left, canHaveOne);
    if(!res.result) return {-1, false};
    Store resRight = helper(root->right, canHaveOne);
    if(!resRight.result) return {-1, false};
    
    if( (res.height - resRight.height) > 1 || (res.height - resRight.height) < 0) {
        return {-1, false};
    }
    return {max(res.height, resRight.height) +1, true};
}

bool solve(Tree* root) {
    bool canHaveOne = true;
    return helper(root, canHaveOne).result;
}