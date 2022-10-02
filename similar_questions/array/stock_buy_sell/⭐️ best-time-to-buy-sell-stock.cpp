// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

/**
 * LOGIC: Keep 2 ptr -> max and min
 * - Decide each time if min or max should be updated and perform operation(checking if got maxProfit)
 * 
 */ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // assign min max both to first index
        int max=INT_MIN;
        int min=INT_MAX;
        int maxProfit=0;
        
        for(int i=0;i<prices.size();i++) {
            //  if curr is larger than max - assign
            max = prices[i]>max ? prices[i] : max;
            
            if(min>prices[i]) {
                min = prices[i];
                max = INT_MIN;
            }
            
            // if curr is smaller than min- assign, max- int_min
            if(min!=INT_MAX && max!=INT_MIN && (max-min)>maxProfit) {
                maxProfit = max - min;
            }
        }
        return maxProfit;
    }
};