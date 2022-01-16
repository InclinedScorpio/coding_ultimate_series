// https://leetcode.com/problems/binary-tree-postorder-traversal/

/**
 * LOGIC: Basic postorder traversal
 * - Must know adding vector to a vector
 * - vec1.insert(vec1.end(), vec2.begin(), vec2.end());
 * - Basically pass end of first vector, and the begin and end of other vector
 * 
 */ 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> leftTree = postorderTraversal(root->left);
        vector<int> rightTree = postorderTraversal(root->right);
        //operation - insertion in vector which has to be returned back
        if(rightTree.size()) 
            leftTree.insert(leftTree.end(), rightTree.begin(), rightTree.end());
                
        //2. Add returned vector to current vector
        leftTree.push_back(root->val);
        
        // return value;
        return leftTree;
        
    }
};