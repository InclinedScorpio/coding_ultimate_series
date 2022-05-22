// https://leetcode.com/problems/unique-paths/

/**
 * Space optisation
 * - As only next row is used, we don't need complete dp
 * - Just use 2 rows that's all
 * 
 * COMPLEXITY: O(N^2)
 * SPACE: O(2N)
 */ 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        curr[n-1]=1;
        
        for(int j=n-2;j>=0;j--) { // filling curr row
            curr[j]=prev[j] + curr[j+1];
        }
        
        prev = curr;
        
        // filling last to top row
        for(int i=m-2;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                curr[j]=prev[j] + curr[j+1];
            }
            prev=curr;
        }
        return curr[0];
    }
};