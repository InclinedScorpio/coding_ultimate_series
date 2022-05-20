/**
 * QUESTION: Given weight and price of boxes 
 * - & max wt the knapsack/bag can hold
 * - Find max price which can be accomodated
 * 
 * LOGIC: As we can either take a box or not (0/1)
 * - We can't go with greedy as otherwise we could have taken the ration and sorted
 * 
 * - Here, as multiple ways needs to be find, recursion is the way to go
 * - On implementing recursion we can see overlapping problems
 * - Hence memoization is implemented (hence it's a DP problem)
 * 
 * COMPLEXITY: O(maxWeight*boxes) 
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int knapsackProblem(vector<int>& wt, vector<int>& price, int remainingWt, int i,
                vector<vector<int>>& dp) {
    if(remainingWt<=0 || i==-1) return 0;
    int currPrice=0, skippedPrice=0;
    if(dp[i][remainingWt]!=-1) return dp[i][remainingWt];
    if(remainingWt-wt[i]>=0)
        currPrice = price[i] + knapsackProblem(wt, price, remainingWt-wt[i], i-1, dp);
    skippedPrice = knapsackProblem(wt, price, remainingWt, i-1, dp);
    return dp[i][remainingWt] = max(currPrice, skippedPrice);
}

int main() {
    int maxWt=11;
    vector<int> wt ={2, 7, 3, 4};
    vector<int> price = {5, 20, 20, 10};
    vector<vector<int>> dp(wt.size(), vector<int>(maxWt+1, -1));
    cout<<knapsackProblem(wt, price, maxWt, wt.size()-1, dp);
}
