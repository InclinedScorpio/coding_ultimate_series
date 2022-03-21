// https://binarysearch.com/problems/Univalue-Tree-Count


/**
 * LOGIC: Basic - thing to note was all the different conditions
 * - Use cout when expected result is not achieved
 *
 */ 
struct NodeDetail {
    int nodeVal;
    bool isSimilar;
    int totalSimilar;
};

NodeDetail helper(Tree* node) {
    if (!node) return {-1, true, 1};

    NodeDetail left = helper(node->left);
    NodeDetail right = helper(node->right);

    if (left.isSimilar && right.isSimilar) {
        if (left.nodeVal == -1 && right.nodeVal == -1) {
            return {node->val, true, 1};
        } else if (left.nodeVal == -1 && right.nodeVal != -1) {
            if (node->val == right.nodeVal) 
                return {node->val, true, 1 + right.totalSimilar};
            else 
                return {node->val, false, right.totalSimilar};
        } else if (left.nodeVal != -1 && right.nodeVal == -1) {
            if (node->val == left.nodeVal) return {node->val, true, 1 + left.totalSimilar};
             else return {node->val, false, left.totalSimilar};
        } else {
            if (node->val == left.nodeVal && node->val == right.nodeVal) 
                return {node->val, true, (1 + left.totalSimilar + right.totalSimilar)};
             else 
                return {node->val, false, left.totalSimilar + right.totalSimilar};
        }
    } else {
        if (left.nodeVal == -1) left.totalSimilar = 0;
        if (right.nodeVal == -1) right.totalSimilar = 0;
        return {node->val, false, left.totalSimilar + right.totalSimilar};
    }
}

int solve(Tree* root) {
    NodeDetail store = helper(root);
    return store.totalSimilar;
}