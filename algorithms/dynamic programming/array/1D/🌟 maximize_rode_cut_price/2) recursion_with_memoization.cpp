/**
 * QUESTION: Cut the rod in such a way that maximum profit is generated
 * 
 * LOGIC: Recursion with memoization (Top down approach)
 * - memoization applied as in the tree we can see multiple time same thing will be found
 * 
 * F(n) = rate[n] + max(f(rodSize-1), f(rodSize-2).....)
 * 
 * 
 * COMPLEXITY: O(SizeOfRod*Rates)
 * - sizeOfRod because from top to down we are going to call them
 * - Rates because on each node we are going to call these rates (it maybe already computed, so only 1 call for each rate from node)
 * 
 */ 
#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

using namespace std;

// Top Down Approach
int cutRodForMaxProfit(vector<int>& rate, int rodSize, int cutPrice, unordered_map<int, int>& dp) {
    if(rodSize==0) return cutPrice;
    int maxValue=INT_MIN;
    for(int i=0;i<rate.size();i++) {
        if(rodSize-(i+1)<0) continue;
            maxValue = max(maxValue, cutRodForMaxProfit(rate, rodSize-(i+1), rate[i], dp));
    }
    return dp[rodSize] =  cutPrice+maxValue;
}

int main() {
    vector<int> rate = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodSize = 8;
    unordered_map<int, int> dp;
    cout<<cutRodForMaxProfit(rate, rodSize, 0, dp);
}