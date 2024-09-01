// https://leetcode.com/problems/longest-increasing-subsequence/

/**
 * Question requires only understanding of recursion and memoization(dp)
 * - Important to notice how/why recursion is done in main method
*/
class Solution {
public:
    int helper(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=0) return dp[ind];
        int maxVal=1;
        for(int i=ind+1; i<nums.size();i++) {
            if(nums[i]>nums[ind]) {
                maxVal = max(maxVal, helper(nums, i, dp)+1);
            }
        }
        return dp[ind] = maxVal;
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxVal = -1;
        vector<int>dp(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++) {
            maxVal = max(maxVal, helper(nums, i, dp));
        }
        return maxVal;
    }
};