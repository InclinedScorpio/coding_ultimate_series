// https://binarysearch.com/problems/Level-Order-Traversal

/**
 * LOGIC: Basic
 * - Logic is to use queue & push and pop at right time
 * - Start with one item already in queue so condition could satisfy
 * 
 */ 
vector<int> solve(Tree* root) {
    queue<Tree*> store;
    vector<int> result;
    store.push(root);

    while(!store.empty()) {
        Tree* node = store.front();
        store.pop();
        if(node->left)
            store.push(node->left);
        if(node->right)
            store.push(node->right);
        result.push_back(node->val);
    }
    
    return result;
}