// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

/**
 * LOGIC: Basic recursion problem only! Don't get scared by hard tag
 * 
 */ 
class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp, int& maxValue) {
        if(i>=matrix.size() || j>=matrix[0].size() || i<0 || j<0) return 0;
        if(dp[i][j]==-1) return 0;
        if(dp[i][j]!=-2) return dp[i][j];

        dp[i][j] = -1; // mark in progress
        int right = 0;
        if(j+1<matrix[0].size() && matrix[i][j+1] > matrix[i][j])
            right = helper(matrix, i, j+1, dp, maxValue);
        int left = 0;
        if(j-1>=0 && matrix[i][j-1] > matrix[i][j])
            left = helper(matrix, i, j-1, dp, maxValue);
        int bottom = 0;
        if(i+1<matrix.size() && matrix[i+1][j] > matrix[i][j])
            bottom = helper(matrix, i+1, j, dp, maxValue);
        int top=0;
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j])
            top = helper(matrix, i-1, j, dp, maxValue);

        dp[i][j] = max(right, max(left, max(bottom, top))) + 1;
        maxValue = max(maxValue, dp[i][j]);
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -2));
        int maxValue=INT_MIN;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                helper(matrix, i, j, dp, maxValue);
            }
        }
        return maxValue;
    }
};