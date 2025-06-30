// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

/***
 * 
 * 
 * Logic: As there can be arbitrarily multiple ways
 * We know we have to go for recursion
 * And as we see multiple small problems go for memo
 * So it becomes a top-down dp problem
 */
class Solution {
    public:
    
        int helper(vector<int>& prices, int ind, vector<int>& dp) {
            if(ind==prices.size()) return 0;
            if(dp[ind]!=-1) return dp[ind];
    
            int gotAt=prices[ind];
            int maxProfitSeen=0;
            for(int i=ind;i<prices.size();i++) {
                // now sell
                if(prices[i] - gotAt>=0) {
                    int currentProfit = prices[i] - gotAt;
                    int furtherProfit = this->helper(prices, i+1, dp);
                    maxProfitSeen=max(maxProfitSeen, currentProfit+furtherProfit);
                }
            }
            return dp[ind]=maxProfitSeen;
        }
    
    
        int maxProfit(vector<int>& prices) {
            vector<int> dp(prices.size()+1, -1);
            return helper(prices, 0, dp);
        }
    };