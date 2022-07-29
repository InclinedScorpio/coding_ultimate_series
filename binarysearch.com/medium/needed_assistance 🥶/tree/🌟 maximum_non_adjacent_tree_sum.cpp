// https://binarysearch.com/problems/Maximum-Non-Adjacent-Tree-Sum

/**
 * LOGIC: Forgot even 2nd time
 * - Don't send data from top to bottom
 * - return it from last
 * - This way at each node we can check if we are taking current root then .second of both
 * - Or else we can merge the max from left and right
 * 
 * GOOD QUESTION!
 * 
 */ 
pair<int, int> helper(Tree* root) {
    if(!root) return {0, 0};

    pair<int,int> left = helper(root->left);
    pair<int, int> right = helper(root->right);

    return {
        root->val+left.second+right.second, 
        max(left.first, left.second) + max(right.first, right.second)
    };
}

int solve(Tree* root) {
    pair<int, int> result = helper(root);
    return max(result.first, result.second);
}