// https://leetcode.com/problems/coin-change-2/


/**
 * LOGIC: Make recursion with memoization first to understand tabular
 * Once recursion is done
 * 1) create dp same as recursion
 * 2) insert base case values as seen from recursion
 * 3) now just replace recursion calls to dp index calls
 * 
 * COMPLEXITY: O(N^2)
 */ 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0)); 
        for(int i=0;i<=coins.size();i++) {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=coins.size();i++) {
            for(int j=1;j<=amount;j++) {
                int total = dp[i-1][j];
                if(j-coins[i-1]>=0) {
                    total+=dp[i][j-coins[i-1]];
                }
                dp[i][j] = total;
            }
        }
        return dp[coins.size()][amount];
    }
};