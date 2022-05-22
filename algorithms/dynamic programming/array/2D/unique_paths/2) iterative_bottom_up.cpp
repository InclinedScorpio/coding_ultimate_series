// https://leetcode.com/problems/unique-paths/submissions/

/**
 * 
 * LOGIC: Intuittion comes from recursion
 * - Just implement the recursion to dp array, that's all
 * 
 * COMPLEXITY: O(N^2)
 * SPACE: O(N^2)
 * 
 * - Can space be reduced further? Yes, as we are only using next row each time
 * 
 */ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1]=1;
        
        for(int j=n-2;j>=0;j--) { // filling last row
            dp[m-1][j]=dp[m][j] + dp[m-1][j+1];
        }
        
        // filling last to top row
        for(int i=m-2;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};