// https://binarysearch.com/problems/Counting-Maximal-Value-Roots-in-Binary-Tree

pair<int, int> findMaxCount(Tree* node) {
    if(!node) return {INT_MIN, 0};

    pair<int, int> left = findMaxCount(node->left);
    pair<int, int> right = findMaxCount(node->right);

    if(node->val>=max(left.first, right.first)) {
        return {node->val, (left.second + right.second)+1};
    }else {
        return {max(left.first, right.first), (left.second + right.second)};
    }
}

int solve(Tree* root) {
    return findMaxCount(root).second;
}
