// https://binarysearch.com/problems/Height-Balanced-Tree

/**
 * LOGIC: Basic recursion
 * - Height is the max depth to end
 * - Do +1 while returning 
 * 
 */ 

int helper(Tree* root) {
    if(!root) return 0;
    int left = helper(root->left);
    if(left==-1) return -1;
    int right = helper(root->right);
    if(right == -1) return -1;
    if(abs(left-right)>1) return -1;
    return max(left, right)+1;
}


bool solve(Tree* root) {
    int result = helper(root);
    if(result== -1) return false;
    return true;

}