// https://leetcode.com/problems/coin-change/

/**
 * Question requires only understanding of recursion and 2D-memoization(dp)
 * 
*/
class Solution {
public:
    int helper(vector<int>& coins, int ind, int currCoins, vector<vector<int>>& store) {
        if(currCoins==0) return 0;
        if(ind>=coins.size() || currCoins<0) return -1;
        if(store[ind][currCoins]!=-1) return store[ind][currCoins];
        int minVal=INT_MAX;
        int val = helper(coins, ind+1, currCoins, store);
        if(val!=-1 && val!=INT_MAX) minVal = min(minVal, val);
        val = helper(coins, ind, currCoins-coins[ind], store);
        if(val!=-1 && val!=INT_MAX) minVal = min(minVal, val+1);
        val = helper(coins, ind+1, currCoins-coins[ind], store);
        if(val!=-1 && val!=INT_MAX) minVal = min(minVal, val+1);
        return store[ind][currCoins] = minVal;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> store(coins.size()+1, vector<int>(amount+1, -1));
        int result = helper(coins, 0, amount, store);
        if(result==INT_MAX) return -1;
        return result;
    }
};