// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * 
 * Problem requires understanding of logic on how to use queue to traverse the tree level by level
 * 
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        q.push(NULL);
        vector<int> storeMe;
        while(q.size()>0) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp) storeMe.push_back(temp->val);
            if(temp && temp->left) {
                q.push(temp->left);
            }
            if(temp && temp->right) {
                q.push(temp->right);
            }
            if(!temp) {
                result.push_back(storeMe);
                if(!q.empty()) q.push(NULL);
                storeMe = {};
            }
        }
        return result;
    }
};

