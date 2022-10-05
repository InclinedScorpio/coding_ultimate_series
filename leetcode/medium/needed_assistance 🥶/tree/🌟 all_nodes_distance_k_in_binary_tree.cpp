// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * LOGIC: Question was simple if it  was a graph
 * - Here difficlty is only that we need to traverse back as well
 * - Traversing back is not possible in tree! But with some extra work we can! How?
 * - Use map to store parent of each node! So that we can traverse back
 * - Also, make sure to use visited array so you don't come back from where traversing path for k
 * 
 */ 
class Solution {
public:
    void traverseAndMarkParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentChildRln) {
        if(!root) return;
        
        if(root->left) {
            parentChildRln[root->left] = root;
        }
        
        if(root->right) {
            parentChildRln[root->right] = root;
        }
        
        traverseAndMarkParent(root->left, parentChildRln);
        traverseAndMarkParent(root->right, parentChildRln);
    }
    
    void traverseAndFind(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& parentChildRln, vector<int>& result, set<TreeNode*>& visited) {
        
        if(!root) return;
        
        if(visited.count(root)) return;
        
        if(k==0) {
            result.push_back(root->val);
            return;
        }
        
        visited.insert(root);
           
        if(parentChildRln.count(root)) {
            traverseAndFind(parentChildRln[root], k-1, parentChildRln, result, visited);
        }
        
        // if left present
        traverseAndFind(root->left, k-1, parentChildRln, result, visited);
        
        // if right present
        traverseAndFind(root->right, k-1, parentChildRln, result, visited);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // mark parents first
        unordered_map<TreeNode*, TreeNode*> store;
        traverseAndMarkParent(root, store);
        
        vector<int> result;
        set<TreeNode*> visited;
        
        // traverse from target, have to go up as well so use map! 
        // use visited array so that don't come back from where you have gone
        // basically you are immitating graph here!
        traverseAndFind(target, k, store, result, visited);
        return result;
    }
};