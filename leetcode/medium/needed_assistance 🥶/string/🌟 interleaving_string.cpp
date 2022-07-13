// https://leetcode.com/problems/interleaving-string/

/**
 * LOGIC: There are 2 things to realize in this question
 * 1) There are many ways possible - hence it's a recursion problem
 * 2) The recursion problem has overlapping sub problems so it's a DP Problem
 * 
 * Understanding 2nd point from above)
 * => Let's say we have s1=aaa... and s2=aaa.... 
 * - s1(0) and s2(0) are taken!
 * - While calculating at index 1 of s1 and index 1 of s2 a false was received
 * - Hence now s2(0) and s1(0) are taken! but now again we came to above point s1(1) and s2(1) which is already calculated as false :(
 * - Hence use DP with memoization!
 * 
 * COMPLEXITY: O(N*M)
 * - (x1, x2) -> At x1 we can have N choices and at x2 we can have M choices
 * 
 */ 
class Solution {
public:
    
    bool helper(string s1, string s2, string s3, int ind, int jnd, int targetInd, unordered_map<string, bool>& dp) {
        if(targetInd==s3.length() && ind ==s1.length() && jnd==s2.length()) return true;
        if(targetInd==s3.length()) return false;
        if(dp.count(to_string(ind) + "*" + to_string(jnd))) {
            return false;
        }
        
        bool res=false;
        if(ind<s1.length() && s1[ind]==s3[targetInd]) {
            res = helper(s1, s2, s3, ind+1, jnd, targetInd+1, dp);
        }
        if(res) return dp[to_string(ind) + "*" + to_string(jnd)] =  true;
        if(jnd<s2.length() && s2[jnd]==s3[targetInd]) {
            res = helper(s1, s2, s3, ind, jnd+1, targetInd+1, dp);
        }
        if(res) return dp[to_string(ind) + "*" + to_string(jnd)] =  true;
        return dp[to_string(ind) + "*" + to_string(jnd)] =  false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string, bool> dp;
        return helper(s1, s2, s3, 0, 0, 0, dp);
    }
};