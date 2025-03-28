// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {

        // bfs or level order traversal
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<vector<int>> result;

        while(!q.empty()) {
            int sizeOfQueue = q.size();
            vector<int> subsetResult;
            for(int i=0;i<sizeOfQueue;i++) {
                TreeNode* topOne = q.front();
                q.pop();
                subsetResult.push_back(topOne->val);
                if(topOne->left) q.push(topOne->left);
                if(topOne->right) q.push(topOne->right);
            }
            result.push_back(subsetResult);
        }
        return result;
    }
};