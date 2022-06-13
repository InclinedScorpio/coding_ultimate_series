// https://binarysearch.com/problems/Longest-Tree-Sum-Path-From-Root-to-Leaf


/**
 * LOGIC: Must know returning structure
 * Rest all basic recursion
 * 
 */ 
struct Result {
    int height;
    int sum;
};

Result helper(Tree* root) {
    if(!root) return {0, 0};
    Result left = helper(root->left);
    Result right = helper(root->right);
    if(left.height==right.height) {
        return {left.height+1, max(left.sum, right.sum) + root->val};
    } else if(left.height>right.height) {
        return {left.height+1, left.sum + root->val};
    } else {
        return {right.height+1, right.sum + root->val};
    }
}

int solve(Tree* root) {
    return helper(root).sum;
}