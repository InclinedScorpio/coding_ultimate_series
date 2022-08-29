// https://leetcode.com/problems/path-sum-iii/

/**
 * LOGIC: This is the first soln I could think of
 * - It's not the best solution
 * - As we are calculating the same subproblems again - we can optimize it further
 * - We are keeping a vector which contains all the sum we have seen till now
 * - In that we are adding current root->val and checking ig we are getting the target required
 * 
 * - The iterative part in recursion can be done in recursion itself
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<long long int> previousSum, int& results) {
        if(!root) return;
        vector<long long int> newSum; // new vector
        for(int i=0;i<previousSum.size();i++) {
            long long sumWithCurrentVal = (long long int)previousSum[i] + root->val;
            if(sumWithCurrentVal == targetSum) results++;
            newSum.push_back(sumWithCurrentVal);
        }
        if(root->val==targetSum) results++;
        newSum.push_back(root->val);
        helper(root->left, targetSum, newSum, results);
        helper(root->right, targetSum, newSum, results);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int results=0;
        helper(root, targetSum, {}, results);
        return results;
    }
};