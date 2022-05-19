// https://leetcode.com/problems/distinct-subsequences/

/**
 * QUESTION: Find number of times the string subsequence of str2 is inside str1
 * 
 * LOGIC: 
 * - It's a recursive problem as we can solve it in multiple ways
 * - As recursive is top down so let's solve it from i, j at last
 * - Basic logic of keeping characters and skipping it is simple
 * - Also it's TLE so we need to memoize and it's overlapping problems (checking making tree)
 * 
 * - While memoization don't take 0 in dp as it will keep reevaluating for mutiple branches as their result would be 0
 * 
 * COMPLEXITY: O(2^N) - exponential
 * SPACE: O(1)
 * 
 **/

class Solution {
    
private:
    int distinctSub(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int noMatch=0, match=0;
        noMatch = distinctSub(s, t, i-1, j, dp);
        if(s[i]==t[j]) {
            match = distinctSub(s, t, i-1, j-1, dp);
        }
        return dp[i][j] = noMatch + match;
    }
    
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return distinctSub(s, t, s.length()-1, t.length()-1, dp);
    }
};