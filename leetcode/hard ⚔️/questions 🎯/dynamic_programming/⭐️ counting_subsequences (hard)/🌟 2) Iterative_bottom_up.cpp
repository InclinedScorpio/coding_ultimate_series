// https://leetcode.com/problems/distinct-subsequences/

/**
 * QUESTION: Find number of times the string subsequence of str2 is inside str1
 * 
 * LOGIC: 
 * - Recursive is already done
 * - This is bottom up approach
 * 1) do the base condition first! It's jotting down those 0's and 1's
 * 2) Now do the operation and return the result as required
 * 
 * COMPLEXITY:
 * O(N*M)
 * 
 * SPACE:
 * O(N*M)
 * - N*M is DP
 * **can be optimized further
 * 
 **/

class Solution {

public:
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(t.length()+1, vector<double>(s.length()+1, 0));
        
        vector<int> curr(0), prev(1);
        for(int i=0;i<=s.length();i++) {
            dp[0][i]=1;
        }
        
        for(int i=1;i<=t.length();i++) {
            for(int j=1;j<=s.length();j++) {
                if(s[j-1]==t[i-1]) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];    
                }
            }
        }
        
        return (int)dp[t.length()][s.length()];
    }
};