// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/**
 * LOGIC: Think greedily, use scatch!
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int low=prices[0], high=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++) {
            if(low>prices[i]) { // stock prices got less than the one when we bought
                profit+=(high-low); // book whatever profit we have
                low = prices[i]; // update both low and high
                high = prices[i]; 
            } else { // prices are definitely high - so either wait or book it
                if(high<prices[i]) { // if it's greater than previous high, update the high
                    high = prices[i];
                } else { // if it's lower than previous high, book the profit
                    profit+=(high-low);
                    low = prices[i];
                    high = prices[i];
                }
            }   
        }
        return profit + (high-low); // at last, profit may not be booked, so include that as well
    }
};