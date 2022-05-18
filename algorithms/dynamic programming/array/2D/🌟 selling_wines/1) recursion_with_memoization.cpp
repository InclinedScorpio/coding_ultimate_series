/**
 * QUESTION: Given wines kept on a shelf
 * - Each year the price of wine will be increased by one
 * - Each year you are required to sell only one wine
 * - Maximize the amount which can be earned selling all wine
 * - Wines can only be picked from extreme left or  extreme right
 * 
 * LOGIC: First let's see greedy works or not
 * - Pick smallest available and keep picking smallest
 * - But this doesn't work!
 * 
 * - Hence we need to pick both left/right - so recursion is the solution
 * - So using solution we see we get overlapping subproblems
 * - Hence it's a DP problem - using memoization here
 * 
 */ 

#include<iostream>
#include<vector>

using namespace std;

int maxPrice(vector<int>& prices, int l, int r, int year, vector<vector<int>>& dp) {
    if(l>r) return 0;
    if(dp[l][r]!=0) return dp[l][r];
    int left = (year * prices[l]) + maxPrice(prices, l+1, r, year+1, dp);
    int right = (year * prices[r]) + maxPrice(prices, l, r-1, year+1, dp);
    return dp[l][r] = max(left, right);
}

int main() {
    vector<int> prices = {2, 3, 5, 1, 4};
    vector<vector<int>> dp(prices.size(), vector<int>(prices.size(), 0));
    cout<<maxPrice(prices, 0, prices.size()-1, 1, dp);
}
