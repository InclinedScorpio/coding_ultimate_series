// https://leetcode.com/problems/decode-ways/

/**
 * LOGIC: Start from recursion - as simple intuition
 * - Once we get TLE, we understand it's a dp problem as it has sub problem
 * - Hence do memoization
 * - Also stoi() takes linear time so that we can prevent by just checking the 2nd digit if more than 6
 * - We can prevent doing that string to int by doing this optimization
 */
class Solution {
public:
    int helper(string& s, int ind, vector<int>& dp) {
        if(ind>=s.length()) return 1;
        if(dp[ind]!=-1) return dp[ind];
        
        string str="";
        int totResults=0;
        
        for(int i=ind;i<s.length();i++) {
            str+=s[i];
            int intFormed = stoi(str);
            if(intFormed==0) return dp[ind] = totResults;
            if(intFormed>0 && intFormed<27) {
                totResults+= helper(s, i+1, dp);
            } else return dp[ind] = totResults;
        }
        return dp[ind] = totResults;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return helper(s, 0, dp);
    }
};