// https://leetcode.com/problems/path-sum-ii/

/**
 * LOGIC: Basic tree problem... just know pass by reference
 *
 */
class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<int> nodes, vector<vector<int>>& result) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(targetSum - root->val==0) {
                nodes.push_back(root->val);
                result.push_back(nodes);   
            }
            return;
        }
        
        nodes.push_back(root->val);
        helper(root->left, targetSum - root->val, nodes, result);
        helper(root->right, targetSum - root->val, nodes, result);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        helper(root, targetSum, {}, result);
        return result;
    }
};

