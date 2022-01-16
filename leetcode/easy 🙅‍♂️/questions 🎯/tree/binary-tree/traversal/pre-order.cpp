// https://leetcode.com/problems/binary-tree-preorder-traversal/

/**
 * LOGIC: Basic preorder traversal
 * - Must know adding vector to a vector
 * - vec1.insert(vec1.end(), vec2.begin(), vec2.end());
 * - Basically pass end of first vector, and the begin and end of other vector
 * 
 */ 
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> treeVal;
        treeVal.push_back(root->val);
        vector<int> leftTreeVal = preorderTraversal(root->left);
        if(leftTreeVal.size())
            treeVal.insert(treeVal.end(), leftTreeVal.begin(), leftTreeVal.end());
        vector<int> rightTreeVal = preorderTraversal(root->right);
        if(rightTreeVal.size())
            treeVal.insert(treeVal.end(), rightTreeVal.begin(), rightTreeVal.end());
        return treeVal;
    }
};
