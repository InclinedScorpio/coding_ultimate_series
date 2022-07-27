// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * LOGIC: Use a queue to store the nodes as you traverse
 * - Just form the list at the last, nothing fancy
 * 
 */
class Solution {
public:
    
    void helper(TreeNode* root, queue<TreeNode*>& store) {
        if(!root) return;
        store.push(root);
        helper(root->left, store);
        helper(root->right, store);
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*> store;
        helper(root, store);
        store.pop();
        while(store.size()) {
            root->right = store.front();
            root->left = NULL;
            root = root->right;
            store.pop();
        }
    }
};