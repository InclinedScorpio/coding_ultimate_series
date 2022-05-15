// https://leetcode.com/problems/unique-binary-search-trees/


/**
 * LOGIC: 1) Is to understand it's a DP Problem
 * - Understand question states 1.. to .. N
 * 
 * Main_logic:
 * - Take each node one by one as root and recurive call both remaining number of nodes
 * - Keep doing this until one node or no node is left - in that case return 1!
 * - Now these sub problems will accumulate and result in solution of this bigger problem!
 * - Hence, Q looks like Tree but is a Dynamic problem question
 * - As it had overlapping subproblem we used cache to use already computed results
 * 
 */ 
class Solution {
public:
    
    int helper(int n, vector<int>& dp) {
        if(n==0 || n==1) return 1;
        if(dp[n]!=0) return dp[n];
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=helper(abs(0-i), dp)*helper(n-i-1, dp);
        }
        return dp[n] = sum;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        return helper(n, dp);
    }
};