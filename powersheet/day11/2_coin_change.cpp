// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if(amount==0) return 0;
        if(amount<0 || i>=coins.size()) return INT_MAX;
        if(dp[amount][i]!=-1) return dp[amount][i];
      

        // pick curr
        long picked = (long)this->helper(coins, amount-coins[i], i, dp);
        if(picked==INT_MAX) picked=INT_MAX;
        else picked++;
        // don't pick curr
        long notPicked = this->helper(coins, amount, i+1, dp);
        return dp[amount][i] = min(picked, notPicked);
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size()+1, -1));
        int result = this->helper(coins, amount, 0, dp);
        return result==INT_MAX?-1: result;
    }
};