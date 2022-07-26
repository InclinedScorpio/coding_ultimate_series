// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * LOGIC: This one uses more space complexity and more linear time complexity
 * - First thing is to understand to find the path to find the node from the root
 * - Next is just to pop both stack and check the last similar node
 * - The last similar node will be the lowest common ancestor
 * 
 * COMPLEXITY: O(N)
 * SPACE: O(2N)
 */ 
class Solution {
public:
    
    bool findPathToNodeFromRoot(TreeNode* root, stack<TreeNode*>& store, TreeNode* toFind) {
        if(!root) return false;
        if(root==toFind) {
            store.push(root);
            return true;
        }
        
        bool left = findPathToNodeFromRoot(root->left, store, toFind);
        if(left) {
            store.push(root);
            return true;
        }
        bool right = findPathToNodeFromRoot(root->right, store, toFind);
        if(right) {
            store.push(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> storeP;
        findPathToNodeFromRoot(root, storeP, p);
        stack<TreeNode*> storeQ;
        findPathToNodeFromRoot(root, storeQ, q);
        
        TreeNode* lca = root;
        while(!storeP.empty() && !storeQ.empty() && storeP.top()==storeQ.top()) {
            lca = storeP.top();
            storeP.pop();
            storeQ.pop();
        }
        return lca;
    }
};