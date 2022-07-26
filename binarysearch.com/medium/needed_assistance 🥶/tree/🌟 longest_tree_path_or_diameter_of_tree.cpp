// https://binarysearch.com/problems/Longest-Tree-Path

/**
 * LOGIC: At each node we just need to find max left and right depth
 * - But that doesn't have to be done at each step, rather make use of recursion
 * - Recursion down to up here helps us to get depth without visited nodes multiple times
 * 
 * COMPLEXITY:O(N)
 *  
 * 
 */ 
int helper(Tree* root, int& result) {
    if(!root) return 0;

    int left = helper(root->left, result);
    int right = helper(root->right, result);

    result = max(left+right+1, result);
    return 1 + max(left, right);
}

int solve(Tree* root) {
    int result=0;
    helper(root, result);
    return result;
}