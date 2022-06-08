// https://binarysearch.com/problems/Most-Frequent-Subtree-Sum

/**
 * LOGIC: It's basic DFS
 * - Point to note is we need to use map & pass by reference
 * - Later just iterate through it and find max
 * 
 * - We can also send another variable by reference and store max while traversing
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(N)
 * 
 */ 
int helper(Tree* root, unordered_map<int, int>& store) {
    if(!root) return 0;
    int left = helper(root->left, store);
    int right = helper(root->right, store);
    store[left+right + root->val]++;
    return left+right + root->val;
}

int solve(Tree* root) {
    unordered_map<int, int> store;
    helper(root, store);
    int count=0;
    int result=0;
    for(auto st: store) {
        if(count<=st.second) {
            result = st.first;
            count = st.second;
        }
    }
    return result;
}