// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/**
 * 
 * Logic- easy: just keep record of smallest seen at each point
 */
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size()==0) return 0;
            int result=0;
            int minTill=prices[0];
            for(int i: prices) {
                result = max(result, i-minTill);
                if(i<minTill)minTill=i;
            }
            return result;
        }
    };