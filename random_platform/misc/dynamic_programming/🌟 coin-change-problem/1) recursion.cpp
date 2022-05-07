/**
 * QUESTION: Given set of coins & value to be created
 * - find min no of coins required to create that value
 * 
 * LOGIC: First thing is that we can have multiple ways hence recursion comes to picture
 * - So using recursion we can't find all possible ways we can reach 15
 * - And from that we will take the smallest possible way
 * 
 * 
 * COMPLEXITY: O(Coins^val)
 * - Can we improve?
 * - Yes, using memoization as we are calculating same things multiple times
 * - As we are finding ways to reach 7 value multiple times, we could have memoized it
 * 
 */ 

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int findMinCoins(vector<int> coins, int totalVal) {
    if(totalVal==0) return 0;
    int minVal=INT_MAX;
    for(int i=0;i<coins.size();i++) {
        if(totalVal-coins[i]<0) continue;
        int val = findMinCoins(coins, totalVal-coins[i]);
        minVal = min(minVal, val);
    }
    return minVal+1;
}

int main() {
    // coins - {1, 3, 7, 10}
    // to create -> 15 | find minimum no of coins required
    vector<int> coins  = {1, 3, 7, 10};
    int totalVal = 15;
    cout<<findMinCoins(coins, totalVal);
}
