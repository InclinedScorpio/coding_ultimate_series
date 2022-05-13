// https://binarysearch.com/problems/Leftmost-Deepest-Tree-Node

/**
 * LOGIC: Basic problem
 * - Important to understand how to return multiple values
 * - ... using struct or class :)
 * 
 */ 
 struct Result {
     int depth;
     int value;
 };

Result helper(Tree* node, int depth) {
    if(!node->left && !node->right) {
        return {depth, node->val};
    }

    Result left = {0, 0};
    if(node->left)
        left = helper(node->left, depth+1);
    
    Result right = {0,0};
    if(node->right)
        right = helper(node->right, depth+1);
        
    if(left.depth>=right.depth) {
        return left;
    } else {
        return right;
    }
}

int solve(Tree* root) {
    return helper(root, 0).value;
}