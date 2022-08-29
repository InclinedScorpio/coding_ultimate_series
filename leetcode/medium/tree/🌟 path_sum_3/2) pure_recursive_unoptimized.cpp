// https://leetcode.com/problems/path-sum-iii/submissions/

/**
 * LOGIC: Here unlike 1) where I was using loop inside each recursion
 * - Here it's pure recursion... as we are going to each node
 * - And then calculating sum from that node to below
 * 
 * - But here as well we are calculating the same thing again, hence we can apply prefix sum
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    int calculateSum(TreeNode* root, long long int targetSum) {
        int count=0;
        if(!root) return count;
        long long int currSum = targetSum - root->val;
        if(currSum==0) count++;
        
        count+=calculateSum(root->left, currSum);
        count+=calculateSum(root->right, currSum);
        return count;
    }
    
    int helper(TreeNode* root, int targetSum) { //goto each node
        if(!root) return 0;
        int total = calculateSum(root, targetSum);
        total += helper(root->left, targetSum);
        total += helper(root->right, targetSum);
        return total;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};