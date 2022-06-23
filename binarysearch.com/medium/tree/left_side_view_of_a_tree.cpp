// https://binarysearch.com/problems/Left-Side-View-of-a-Tree

/**
 * LOGIC: Basic, just keep a note of the maxDepth
 * 
 * - New depth count means, that must be some node which will be seen from the left
 * 
 */ 
void helper(Tree* root, vector<int>& result, int currDepth, int& maxDepth) {
    if(!root) return;
    if(currDepth>maxDepth) result.push_back(root->val);
    if(currDepth>maxDepth) maxDepth = currDepth;

    helper(root->left, result, currDepth+1, maxDepth);
    helper(root->right, result, currDepth+1, maxDepth);
}


vector<int> solve(Tree* root) {
    vector<int> result;
    int depth = -1;
    helper(root, result, 0, depth);
    return result;
}