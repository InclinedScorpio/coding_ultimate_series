https://leetcode.com/problems/climbing-stairs/

/**
 * Question requires only understanding of recursion and memoization(dp)
*/
class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n]; // memoization
        dp[n] = helper(n-1, dp) + helper(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};