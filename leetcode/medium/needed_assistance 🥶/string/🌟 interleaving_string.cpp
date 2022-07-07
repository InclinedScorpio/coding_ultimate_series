// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    
    bool helper(string s1, string s2, string s3, int ind, int jnd, int targetInd, unordered_map<string, bool>& dp) {
        if(targetInd==s3.length() && ind ==s1.length() && jnd==s2.length()) return true;
        if(targetInd==s3.length()) return false;
        if(dp.count(to_string(ind) + "*" + to_string(jnd) + "*")) {
            return dp[to_string(ind) + "*" + to_string(jnd) + "*"];
        }
        
        bool res=false;
        if(ind<s1.length() && s1[ind]==s3[targetInd]) {
            res = helper(s1, s2, s3, ind+1, jnd, targetInd+1, dp);
        }
        if(res) return dp[to_string(ind) + "*" + to_string(jnd) + "*"] =  true;
        if(jnd<s2.length() && s2[jnd]==s3[targetInd]) {
            res = helper(s1, s2, s3, ind, jnd+1, targetInd+1, dp);
        }
        if(res) return dp[to_string(ind) + "*" + to_string(jnd) + "*"] =  true;
        return dp[to_string(ind) + "*" + to_string(jnd) + "*"] =  false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string, bool> dp;
        return helper(s1, s2, s3, 0, 0, 0, dp);
    }
};