// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * LOGIC: intuition comes from scratch
 * - Make tree and use arrows to denote how to pick numbers
 * - Also, using more than 1 array, stack, queue should also be checked
 *
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> first;
        stack<TreeNode*> second;
        if(root) first.push(root);
        bool isLeftToRight=true;
        vector<vector<int>> result;
        while(!first.empty() || !second.empty()) {
            vector<int> resultPart;
            while(!first.empty()) {
                TreeNode* top = first.top();
                first.pop();
                resultPart.push_back(top->val);
                if(top->left) second.push(top->left);
                if(top->right) second.push(top->right);
            }
            if(!resultPart.empty()) result.push_back(resultPart);
            resultPart = {};
            while(!second.empty()) {
                TreeNode* top = second.top();
                second.pop();
                resultPart.push_back(top->val);
                if(top->right) first.push(top->right);
                if(top->left) first.push(top->left);
            }
            if(!resultPart.empty()) result.push_back(resultPart);
        }
        return result;
    }
};