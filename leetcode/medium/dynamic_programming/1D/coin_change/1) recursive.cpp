// https://leetcode.com/problems/coin-change/

/**
 * LOGIC: We need to think about recusive solution first
 * - Thinking recursive is easy here as we just need to keep picking the same coin till it exceeds amount
 * - If it does then we can pick next index and start reducing amount through that coin size
 *
 * 
 * - We realize this is a dp problem as it is having similar sub problems
 * 
 */ 
class Solution {
public:
    
    int helper(vector<int>& coins, int amount, int ind, vector<vector<int>>& store) {
        if(amount==0) return 0;
        if(ind>=coins.size() || amount<0) return -1;
        
        if(store[amount][ind]) {
            return store[amount][ind];
        }
        
        int taken = helper(coins, amount - coins[ind], ind, store);
        int notTaken = helper(coins, amount, ind+1, store);
        if(taken!=-1 && notTaken!=-1) {
            if(taken<notTaken) {
                return store[amount][ind] = taken + 1;
            } else {
                return store[amount][ind] = notTaken;
            }
        }
        
        if(taken!=-1)
            return store[amount][ind] = taken+1;
        else return store[amount][ind] = notTaken;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<vector<int>> store(amount+1, vector<int>(coins.size(), 0));
        return helper(coins, amount, 0, store);
    }
};