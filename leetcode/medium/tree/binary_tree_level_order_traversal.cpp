// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * LOGIC: Only 2 things to understand
 * - Usage of queue
 * - Entering NULL after root and entering NULL again when NULL encountered
 * - Null acts as the end of the row!
 * 
 * COMPLEXITY:O(N)
 * 
 */ 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {}; // edge-case
        
        queue<TreeNode*> store;
        store.push(root);
        store.push(NULL);
        vector<vector<int>> result;

        vector<int> nestedRes;
        while(!store.empty()) {
            TreeNode* node = store.front();
            if(!node) {
                result.push_back(nestedRes);
                nestedRes = {};
                store.pop();
                if(store.empty()) return result; 
                store.push(NULL);
                continue;
            }
            store.pop();
            nestedRes.push_back(node->val);
            if(node->left)
                store.push(node->left);
            if(node->right)
                store.push(node->right);
        }
        return result;
    }
};