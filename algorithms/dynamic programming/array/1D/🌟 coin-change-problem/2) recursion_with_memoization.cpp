


/**
 * QUESTION: Given set of coins & value to be created
 * - find min no of coins required to create that value
 * 
 * TOP DOWN APPROACH (recursion + memoization)
 * LOGIC: This time we are using recursion with memoization
 * - For memoization, use unordered map or an array (as key value pair required)
 * - We can use the min value calculated for a set of value & use it everytime
 * - F(N) = min( F(N-coins[i]), F(N-coins[i-1], ...) + 1
 * ☝️ This is equation formed, this can be now used to form bottom up approach
 * 
 * COMPLEXITY: O(val*coins)
 */ 

#include<iostream>
#include<vector>
#include<climits> 
#include<unordered_map>

using namespace std;

int findMinCoins(vector<int> coins, int totalVal, int* dp) {
    if(totalVal==0) return 0;
    if(dp[totalVal]!=0) return dp[totalVal];
    int minVal=INT_MAX;
    for(int i=0;i<coins.size();i++) {
        if(totalVal-coins[i]<0) continue;
        int val = findMinCoins(coins, totalVal-coins[i], dp);
        minVal = min(minVal, val);
    }
    return dp[totalVal] = minVal+1;
}

int main() {
    // coins - {1, 3, 7, 10}
    // to create -> 15 | find minimum no of coins required
    vector<int> coins  = {1, 3, 7, 10};
    int totalVal = 15;
    int dp[10000] = {0};
    cout<<findMinCoins(coins, totalVal, dp);
}
