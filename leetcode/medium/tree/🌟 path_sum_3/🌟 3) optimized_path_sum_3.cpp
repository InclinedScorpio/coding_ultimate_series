// https://leetcode.com/problems/path-sum-iii/submissions/


/**
 * LOGIC: The intution is if we have a, b, c, d, e
 * And we need to find x sum
 * - Then we can start summing up the values
 * - And find (sum - x) - if we have seen it before somwhere while doing sum..
 * - That means it exists in there
 * - The above is called as prefix sum.
 * 
 * COMPLEXITY: O(N)
 */ 
class Solution {
public:
    int helper(TreeNode* root, int targetSum, long long int currSum, unordered_map<long long int, int> store) {
        if(!root) return 0;
        
        int result=0;
        currSum = currSum + (long long int)root->val;
        long long int findSum = currSum - targetSum;
        if(store.find(findSum)!=store.end()) {
            result+=store[currSum - targetSum];
        }
        store[currSum]++;
        result+=helper(root->left, targetSum, currSum, store);
        result+=helper(root->right, targetSum, currSum, store);
        return result;
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long int, int> store;
        store[0] = 1;
        return helper(root, targetSum, 0, store);
    }
};