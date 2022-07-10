// https://leetcode.com/problems/jump-game-vi/

/**
 * LOGIC: Basic DP Question with memoization
 * - Point to note is to return the result from the last- then only memo is possible
 * 
 * - BUT here TLE is received, means there is a better solution possible
 * - As we are asked to jump upto k steps, we can keep a note of max value in those k
 * - And add that to next index and then insert the value formed at new index to the records inside k
 * - That would be just O(nlogN)- checkout 2) solution for the details
 * 
 * COMPLEXITY: O(N^2)
 * TLE! 
 * 
 */
class Solution {
public:
    // int dp[100001];
    int helper(vector<int>& nums, int ind, int k, vector<int>& dp) {
        if(ind==nums.size()-1) return nums[nums.size()-1];
        if(dp[ind]!=INT_MIN) {
            return dp[ind];
        }
        int maxVal=INT_MIN;
        for(int i=1;i<=k;i++) {
            if(ind+i>=nums.size()) break;
            maxVal = max(maxVal, helper(nums, ind+i, k, dp)+nums[ind]);
        }
        // cout<<maxVal<<endl;
        return dp[ind] = maxVal;
    }
    
    int maxResult(vector<int>& nums, int k) {
        // memset(dp, -1, sizeof dp);
        vector<int>dp (100001, INT_MIN);
        return helper(nums, 0, k, dp);
    }
};