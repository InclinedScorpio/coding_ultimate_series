// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> myVector;
    
    void inOrder(TreeNode* node) {
        if(!node) {
            return;
        }
        inOrder(node->left);
        this->myVector.push_back(node->val);
        inOrder(node->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return this->myVector;
    }
};