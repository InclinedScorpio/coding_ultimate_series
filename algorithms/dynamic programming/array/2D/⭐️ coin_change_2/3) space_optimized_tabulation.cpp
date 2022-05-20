// https://leetcode.com/problems/coin-change-2/

/**
 * LOGIC: In tabulation as we are only concerned with previous row
 * - We can make use of two array O(N) rather than O(N*M)
 * 
 */ 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        vector<int> curr(amount+1, 0);
        vector<int> prev(amount+1, 0);
        
        for(int i=1;i<=coins.size();i++) {
            curr[0]=1;
            for(int j=1;j<=amount;j++) {
                int total = prev[j];
                if(j-coins[i-1]>=0) {
                    total+=curr[j-coins[i-1]];
                }
                curr[j] = total;
            }
            prev=curr;
        }
        return prev[amount];
    }
};