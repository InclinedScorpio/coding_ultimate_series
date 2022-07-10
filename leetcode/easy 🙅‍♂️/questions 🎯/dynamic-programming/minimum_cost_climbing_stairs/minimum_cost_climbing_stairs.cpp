// https://leetcode.com/problems/min-cost-climbing-stairs/

/**
 * LOGIC: Basic DP Problem
 * - Recursion with memoization
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
class Solution {
public:
    int dp[1001];
    int helper(vector<int>& cost, int ind) {
        if(ind>=cost.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int oneCost = helper(cost, ind+1);
        int twoCost = helper(cost, ind+2);
        
        return dp[ind] = min(oneCost, twoCost) + cost[ind];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof dp);
        int zerothStart = helper(cost, 0);
        int oneStart = helper(cost, 1);
        return min(zerothStart, oneStart);
    }
};