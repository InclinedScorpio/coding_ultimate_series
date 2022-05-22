// https://leetcode.com/problems/unique-paths/

/**
 * LOGIC: Basic
 * - As multiple ways are possible, we will go for recursion
 * - But here we see lots of overlapping problem
 * - Hence DP can be implemented
 * 
 * COMPLEXITY: O(N^2)
 * 
 */ 
class Solution {
public:
    int helper(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int belowCount = helper(m, n, i+1, j, dp);
        int rightCount = helper(m, n, i, j+1, dp);
        return dp[i][j]=belowCount+rightCount;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m, n, 0, 0, dp);
    }
};