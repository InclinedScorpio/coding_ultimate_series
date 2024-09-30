// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/**
 * 2 pointer approach to keep min from left and max from right
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<int> rightMaxView(prices.size(), 0);
        int rightMax=0;
        for(int i=prices.size()-1;i>=0;i--) {
            rightMaxView[i] = max(rightMax, prices[i]);
            rightMax = rightMaxView[i];
        }

        int maxProfitFound=0;
        int leftMin=INT_MAX;
        for(int i=0;i<prices.size();i++) {
            leftMin = min(leftMin, prices[i]);
            maxProfitFound = max(maxProfitFound, (rightMaxView[i]-leftMin));
        }
        return maxProfitFound>=0 ? maxProfitFound : 0;

        
    }
};