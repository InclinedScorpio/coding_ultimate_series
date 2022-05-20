// https://leetcode.com/problems/coin-change-2/

/**
 * LOGIC: Basic recursion based on question
 * - We are required to have all different possible solutions
 * - And need to return the addition of result as all possible ways required
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
private:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if(amount==0) return 1;
        if(amount<0||i<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int skipThis=helper(coins, amount, i-1, dp);
        int doNotSkip=helper(coins, amount-coins[i], i, dp);
        return dp[i][amount] = skipThis+doNotSkip;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1)); 
        return helper(coins, amount, coins.size()-1, dp);
    }
};
