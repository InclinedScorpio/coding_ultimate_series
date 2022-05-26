// https://leetcode.com/problems/russian-doll-envelopes/

/**
 * LOGIC: Basic recursion
 * Point is to sort and check all previous cards whichever can fit
 * 
 * COMPLEXITY: O(N^2) - gives TLE !
 * Q) Can we optimize it?
 * A) Yes, we can use LIS! 
 * 
 */ 
class Solution {
public:
    int helper(vector<vector<int>>& envelopes, int iter, vector<int>& dp) {
        if(iter==0) return 1;
        if(dp[iter]!=-1) {
            return dp[iter];
        }
        int currMax = 0;
        for(int i=iter-1;i>=0;i--) {
            if(envelopes[i][0]<envelopes[iter][0]
                && envelopes[i][1]<envelopes[iter][1]) {
                currMax = max(currMax, helper(envelopes, i, dp));
            }
        }
        return dp[iter] = currMax+1;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int currMax=INT_MIN;
        vector<int> dp(envelopes.size(), -1);
        for(int i=envelopes.size()-1;i>=0;i--) {
            currMax = max(currMax, helper(envelopes, i, dp));
        }
        return currMax;
    }
};