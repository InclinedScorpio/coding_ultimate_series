// https://leetcode.com/problems/coin-change/

/**
 * LOGIC: Do recursive and then memoize - basic dp question
 * 
 */ 
class Solution {
public:
    int helper(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        if(amount==0) return 0;
        if(ind>=coins.size() || amount<0) return -2;
        if(dp[ind][amount]!=-100) return dp[ind][amount];
        
        // Taken
        int minCoins=INT_MAX;
        int res = helper(coins, ind, amount-coins[ind], dp) + 1;
        if(res>=0) minCoins=res;
        
        // Not Taken
        res = helper(coins, ind+1, amount, dp);
        if(res>=0 && res<minCoins) minCoins=res;

        return dp[ind][amount] = (minCoins==INT_MAX ? -2 : minCoins);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -100));
        int res = helper(coins, 0, amount, dp);
        if(res<0) return -1;
        else return res;
    }
};