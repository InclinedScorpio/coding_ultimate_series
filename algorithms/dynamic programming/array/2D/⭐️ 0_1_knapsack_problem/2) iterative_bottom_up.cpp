/**
 * QUESTION: Given weight and price of boxes 
 * - & max wt the knapsack/bag can hold
 * - Find max price which can be accomodated
 * 
 * LOGIC: Comes from recursion with memoization
 * - We just need to implement the recursion to dp tabular form
 * - weights & indices we are taking and checking if weight can fit in current index
 * - Also we are checking - wt of curr index to check if remaining wt can accomodate any other box [i-1][wt-j]
 * 
 * - Above things don't need to memorize, it comes from recursion with memo
 * 
 * COMPLEXITY: O(maxWeight*boxes) 
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int maxWt=11;
    vector<int> wt ={2, 7, 3, 4};
    vector<int> price = {5, 20, 20, 10};
    vector<vector<int>> dp(wt.size()+1, vector<int>(maxWt+1, 0));

    for(int i=1;i<=wt.size();i++) {
        for(int j=1;j<=maxWt;j++) {
            int maxValue=0;
            if(j-wt[j]>=0 && wt[i+1]<=j) {
                maxValue = price[i+1] + dp[i-1][j-wt[j]];
            } else {
                if(wt[i+1]<=j) {
                    maxValue = max(maxValue, price[i+1]);
                }
            }
            dp[i][j] = max(maxValue, dp[i-1][j]);
        }
    }
    cout<<dp[wt.size()][maxWt];
}
