// https://leetcode.com/problems/selling-pieces-of-wood/

/**
 * LOGIC: Problem is a basic dp problem - just understand question properly
 */
class Solution {
public:
    long long helper(int rows, int cols, vector<vector<int>>& prices, 
                    vector<vector<long long>>& dp) {
        if(rows==0 || cols==0) return 0;
        if(dp[rows][cols]!=-1) return dp[rows][cols];

        long long maxMoney = prices[rows][cols];
        
        // cut from row
            for(int i=1;i<rows;i++) {
                    long long currMaxPrice1 = helper(i, cols, prices, dp); 
                    long long currMaxPrice2 = helper(rows-i, cols, prices, dp);
                    maxMoney = max(currMaxPrice1 + currMaxPrice2, maxMoney);
            }
        
        // cut from col
            for(int i=1;i<cols;i++) {
                    long long currMaxPrice1 = helper(rows, i, prices, dp);
                    long long currMaxPrice2 = helper(rows, cols-i, prices, dp);
                    maxMoney = max(currMaxPrice1 + currMaxPrice2, maxMoney); 
            }
        
        return dp[rows][cols] = maxMoney;        
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> myArrPrice(m+1, vector<int>(n+1, 0));

        for(int i=0;i<prices.size();i++)
            myArrPrice[prices[i][0]][prices[i][1]]=prices[i][2];
        
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, -1));
    
        return helper(m, n, myArrPrice, dp);
    }
};