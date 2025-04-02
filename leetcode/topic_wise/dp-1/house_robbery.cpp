// https://leetcode.com/problems/house-robber/description/

/**
 * Basic DP problem, think of recursion to cover all case and then use memoization
 */
class Solution {
public:

    int helper(vector<int>& nums, int i, vector<int>& dp) {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int maxSeen=0;
        // pick
        maxSeen = helper(nums, i+2, dp) + nums[i];
        // don't pick
        maxSeen = max(maxSeen, helper(nums, i+1, dp));

        return dp[i]=maxSeen;
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};