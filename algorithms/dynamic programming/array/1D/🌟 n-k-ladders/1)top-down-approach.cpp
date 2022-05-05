/**
 * QUESTION: Given total stairs, and number of steps/hops which can be made
 * - Find number of ways to reach the final stair from ground
 * 
 * LOGIC:
 * - It's clear case of recursion as it's forming a tree
 *                    4
 *          4         3        2
 *       3  2  1    2  1 0    1  0 
 *      . . . (for 0 we will return 1)
 * 
 * Hence, we get idea it's recursion!
 * 
 * Recursion version is given below
 * DP is included to optimize it as it's having overlapping subproblems
 * 
 * DP is used because it's case of both optimal substructure & overlapping subproblem
 * 
 * In recursion we can understand fn(n) = fn(n-1) + fn(n-2) + fn(n-3)
 * Hence, using this function we can also create a Bottom UP Approach (Iterative)
 * 
 * COMPLEXITY: 
 * Recursion is O(k^N)
 * Recursion with memoization: O(Nk) - because at every step we atleast have to see 3(k) steps - it's different thing we already have it's solution
 * ☝️ Top Down Approach
 * 
 */ 

#include<iostream>
#include<unordered_map>

using namespace std;

int findTotalSteps(int ladders, int steps, unordered_map<int, int>& dp) {
    if(ladders==0) return 1;
    if(ladders<0) return 0;
    if(dp.count(ladders)) return dp[ladders]; // using memoization
    
    int count=0;
    for(int i=1;i<=steps;i++) {
        count+=findTotalSteps(ladders-i, steps, dp);
    }
    return dp[ladders] = count;
}

int main() {
    int ladders = 4;
    int steps = 3;
    unordered_map<int, int> dp;
    cout<<findTotalSteps(ladders, steps, dp);
}
