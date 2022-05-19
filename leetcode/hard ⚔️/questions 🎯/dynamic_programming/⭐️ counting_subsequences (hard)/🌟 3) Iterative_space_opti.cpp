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
 * O(N+M)
 * 
 **/

class Solution {

public:
    int numDistinct(string s, string t) {
        vector<double> curr(s.length()+1, 0), prev(s.length()+1, 1);
        for(int i=1;i<=t.length();i++) {
            for(int j=1;j<=s.length();j++) {
                if(s[j-1]==t[i-1]) {
                    curr[j] = curr[j-1] + prev[j-1];
                } else {
                    curr[j] = curr[j-1];
                }
            }
            prev = curr;
        }
        return (int)prev[s.length()];
    }
};